function CWebSocket(msgHandler)
{
	this.mServer 		= "192.168.9.1";
	this.mPort   		= "18000";
	this.mWebSocketUri 	= "ws://" + this.mServer + ":" + this.mPort;
	this.mWebSocket		= null;
	this.mMsgHandler	= msgHandler;
}
CWebSocket.prototype.init  = function()
{
	try
	{
		if( typeof MozWebSocket == 'function')
		{
			WebSocket = MozWebSocket;
		}
		if( this.mWebSocket && (this.mWebSocket.readyState == 1) )
		{
			this.mWebSocket.close();
		}
		this.mWebSocket = new WebSocket(this.mWebSocketUri);
		this.mWebSocket.binaryType = "arraybuffer";
		this.mWebSocket.onopen  = function(evt) {alter("connected");};
		this.mWebSocket.onclose = function(evt) {};
		this.mWebSocket.onmessage = this.mMsgHandler;
	}
	catch(exception)
	{
		alert("(CWebSocket.init()) Exception: " + exception);
		
	};
};
CWebSocket.prototype.close = function()
{
	if(this.mWebSocket)
	{
		this.mWebSocket.close();
	}
};

