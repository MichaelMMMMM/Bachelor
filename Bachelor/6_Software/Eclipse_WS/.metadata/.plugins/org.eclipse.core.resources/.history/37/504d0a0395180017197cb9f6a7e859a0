var testHandler;
var webSocket;

function onLoadJS()
{
	testHandler = new CTestHandler();
	webSocket   = new CWebSocket(testHandler.handleMessage);
	testHandler.handleMessage(1);
}
function onConnectClicked()
{
	webSocket.init();
}
function onDisconnectClicked()
{
	webSocket.close();
}