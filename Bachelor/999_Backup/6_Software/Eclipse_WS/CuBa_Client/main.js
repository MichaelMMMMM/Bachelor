var gPhiPlot;
var gPlot2;
var gPlot3;
var webSocket;

function onLoadJS()
{
	webSocket   = new CWebSocket(onMessage);
	gPhiPlot    = new CPlot("placeholder", 2, ["phi1", "phi2"]);
	gPlot2	    = new CPlot("placeholder2", 1, ["asdf"]);
	gPlot3	    = new CPlot("placeholder3", 3, ["was", "geht", "ab"]);
}
function onMessage(evt)
{
	var data = JSON.parse(evt.data);
	gPhiPlot.addData([data.time, data.phi1, data.phi2]);
}
function onConnectClicked()
{
	webSocket.init();
}
function onDisconnectClicked()
{
	webSocket.close();
}





