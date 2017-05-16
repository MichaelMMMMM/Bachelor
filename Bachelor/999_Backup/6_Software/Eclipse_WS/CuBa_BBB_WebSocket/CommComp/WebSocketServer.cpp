/** --------------------------------------------------------------------------
 *  WebSocketServer.cpp
 *
 *  Base class that WebSocket implementations must inherit from.  Handles the
 *  client connections and calls the child class callbacks for connection
 *  events like onConnect, onMessage, and onDisconnect.
 *
 *  Author    : Jason Kruse <jason@jasonkruse.com> or @mnisjk
 *  Copyright : 2014
 *  License   : BSD (see LICENSE)
 *  -------------------------------------------------------------------------- 
 **/

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>

#include "Util.h"
#include "WebSocketServer.h"

using namespace std;

#define PER_SESSION_DATA_SIZE 4
#define MAX_RXBUFFER_SIZE 1024

// Nasty hack because certain callbacks are statically defined
WebSocketServer *self;


//typedef int lws_callback_function(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);
static int callback_main( 	struct lws *wsi,
                            enum lws_callback_reasons reason,
                            void *user, 
                            void *in, 
                            size_t len )
{
    int fd;
    
    switch( reason ) {
        case LWS_CALLBACK_ESTABLISHED:
        	Util::log("LWS_CALLBACK_ESTABLISHED");
            self->onConnectWrapper( lws_get_socket_fd( wsi ) );
            lws_callback_on_writable( wsi );
            break;

        case LWS_CALLBACK_HTTP: {
				char *requested_uri = (char*) in;
				Util::log("LWS_CALLBACK_HTTP - Requested URI " );

				if (strcmp(requested_uri, "/") == 0) {
					string universal_response = "Hello, World!";
					lws_write(wsi, (unsigned char*)universal_response.c_str( ), universal_response.length(), LWS_WRITE_HTTP);
				}
			}
			break;

        case LWS_CALLBACK_SERVER_WRITEABLE:
        	//Util::log("LWS_CALLBACK_SERVER_WRITEABLE");

            fd = lws_get_socket_fd( wsi );
            while( !self->connections[fd]->buffer.empty() )
            {
				string message = self->connections[fd]->buffer.front();

				int nLength = message.length();

				if(nLength<=0) // no Text ? => then don't send anything
					break;

				// PREPARE MESSAGE
				unsigned char buf[LWS_PRE + nLength];
				memset(&buf[LWS_PRE], 0, nLength); // zeros
				memcpy(&buf[LWS_PRE], message.c_str(), nLength); // copy text

				//Send a Message to Client
				//int charsSent = lws_write( wsi, (unsigned char*)message.c_str(), message.length(), LWS_WRITE_TEXT );
				int charsSent = lws_write(wsi, &buf[LWS_PRE], nLength, LWS_WRITE_TEXT);
				// Something is wrong with the connection
                if (charsSent < 0)
                {
                	Util::log("libwebsocket_write: CharsSent:" + Util::toString(charsSent) + ", MessageLength: " + Util::toString(message.length()) + ", Message: \"" + message + "\" => FAILED");
                	self->onErrorWrapper( fd, string( "Error writing to socket" ) );
                	return -1; // Kills Connection
                }
                //TODO: incomplete sent message.. => error, but we can try send it again, but should it close the connection?!
                else if ((unsigned int)charsSent < message.length())
                {
                	Util::log("libwebsocket_write: CharsSent:" + Util::toString(charsSent) + ", MessageLength: " + Util::toString(message.length()) + ", Message: \"" + message + "\" => INCOMPLETE WRITE");
                	self->onErrorWrapper( fd, string( "Error writing to socket" ) );
                }
                else
                {
                	//Util::log("libwebsocket_write: CharsSent:" + Util::toString(charsSent) + ", MessageLength: " + Util::toString(message.length()) + ", Message: \""+ message +"\" => SUCCESSFUL");

                    // Only pop the message if it was sent successfully.
                    self->connections[fd]->buffer.pop_front( );
                }

            	if (lws_send_pipe_choked(wsi)) {
					lws_callback_on_writable(wsi);
					break;
				}
            }

            break;
        
        case LWS_CALLBACK_RECEIVE:
        	Util::log("LWS_CALLBACK_RECEIVE");
            self->onMessage( lws_get_socket_fd( wsi ), string( (const char *)in ) );
            break;

        case LWS_CALLBACK_CLOSED:
        	Util::log("LWS_CALLBACK_CLOSED");
            self->onDisconnectWrapper( lws_get_socket_fd( wsi ) );
            break;

        case LWS_CALLBACK_PROTOCOL_INIT:
        	Util::log("LWS_CALLBACK_PROTOCOL_INIT");
        	break;

        case LWS_CALLBACK_PROTOCOL_DESTROY:
        	Util::log("LWS_CALLBACK_PROTOCOL_DESTROY");
        	break;

        default:
        	//Util::log("Unknown Callback_Reason: " + Util::toString( reason ));
            break;
    }

    return 0;
}


// ORIGINAL
static struct lws_protocols protocols[] = {
    {
        "test",										// hier steht der Protokollname
        callback_main,
		PER_SESSION_DATA_SIZE, // per session data struct (see below)
        MAX_RXBUFFER_SIZE,
    },{ NULL, NULL, 0, 0 } // terminator
};


struct per_session_data{
	int fd;
};




WebSocketServer::WebSocketServer( int port, const string certPath, const string& keyPath )
{
    this->_port     = port;
    this->_certPath = certPath;
    this->_keyPath  = keyPath; 

    lws_set_log_level( 0, lwsl_emit_syslog ); // We'll do our own logging, thank you.
    struct lws_context_creation_info info;
    memset( &info, 0, sizeof info );
    info.port = this->_port;
    info.iface = NULL;
    info.protocols = protocols;
    
    if( !this->_certPath.empty( ) && !this->_keyPath.empty( ) )
    {
        Util::log( "Using SSL certPath=" + this->_certPath + ". keyPath=" + this->_keyPath + "." );
        info.ssl_cert_filepath        = this->_certPath.c_str( );
        info.ssl_private_key_filepath = this->_keyPath.c_str( );
    } 
    else 
    {
        Util::log( "Not using SSL" );
        info.ssl_cert_filepath        = NULL;
        info.ssl_private_key_filepath = NULL;
    }
    info.gid = -1;
    info.uid = -1;
    info.options = 0;

    // keep alive
    info.ka_time = 60; // 60 seconds until connection is suspicious
    info.ka_probes = 10; // 10 probes after ^ time
    info.ka_interval = 10; // 10s interval for sending probes

    this->_context = lws_create_context( &info );
    if( !this->_context )
        throw "libwebsocket init failed";
    Util::log( "WebSocketServer started on port " + Util::toString( this->_port ) );

    // Some of the libwebsocket stuff is define statically outside the class. This 
    // allows us to call instance variables from the outside.  Unfortunately this
    // means some attributes must be public that otherwise would be private.
    self = this;
}

WebSocketServer::~WebSocketServer( )
{
    // Free up some memory
    for( map<int,Connection*>::const_iterator it = this->connections.begin( ); it != this->connections.end( ); ++it )
    {
        Connection* c = it->second;
        this->connections.erase( it->first );
        delete c;
    }
}

void WebSocketServer::TriggerAllProtocolsCallback() {

	lws_callback_on_writable_all_protocol(this->_context, protocols);
}



void WebSocketServer::onConnectWrapper( int socketID )
{
    Connection* c = new Connection;
    c->createTime = time( 0 );
    this->connections[ socketID ] = c;
    this->onConnect( socketID );
}

void WebSocketServer::onDisconnectWrapper( int socketID )
{
    this->onDisconnect( socketID );
    this->_removeConnection( socketID );
}

void WebSocketServer::onErrorWrapper( int socketID, const string& message )
{
    Util::log( "Error: " + message + " on socketID '" + Util::toString( socketID ) + "'" ); 
    this->onError( socketID, message );
    this->_removeConnection( socketID );
}

void WebSocketServer::send( int socketID, string data )
{
    // Push this onto the buffer. It will be written out when the socket is writable.
    this->connections[socketID]->buffer.push_back( data );
}

void WebSocketServer::broadcast( string data )
{
    for( map<int,Connection*>::const_iterator it = this->connections.begin( ); it != this->connections.end( ); ++it )
        this->send( it->first, data );
}

void WebSocketServer::setValue( int socketID, const string& name, const string& value )
{
    this->connections[socketID]->keyValueMap[name] = value;
}

string WebSocketServer::getValue( int socketID, const string& name )
{
    return this->connections[socketID]->keyValueMap[name];
}

int WebSocketServer::getNumberOfConnections( )
{
    return this->connections.size( );
}

void WebSocketServer::run( uint64_t timeout )
{
    while( 1 )
    {
        this->wait( timeout );
    }
}

void WebSocketServer::wait( uint64_t timeout )
{
    if( lws_service( this->_context, timeout ) < 0 )
        throw "Error polling for socket activity.";
}

void WebSocketServer::_removeConnection( int socketID )
{
    Util::log( "WebSocketServer::_removeConnection with SocketID: " + Util::toString( socketID ) + " " );

    Connection* c = this->connections[ socketID ];
    this->connections.erase( socketID );
    delete c;
}
