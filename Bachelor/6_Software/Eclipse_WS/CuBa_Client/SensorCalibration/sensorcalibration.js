var gSensor1Plot;
var gSensor2Plot;
var gSensor3Plot;
var gSensor4Plot;
var gSensor5Plot;
var gSensor6Plot;

var gWebSocket;

function onLoadJS()
{
	gWebSocket = new CWebSocket(onMessage);

	gSensor1Plot = new CPlot("Sensor1PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
	gSensor2Plot = new CPlot("Sensor2PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
	gSensor3Plot = new CPlot("Sensor3PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
	gSensor4Plot = new CPlot("Sensor4PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
	gSensor5Plot = new CPlot("Sensor5PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
	gSensor6Plot = new CPlot("Sensor6PlotID", 6, ["a_x", "a_y", "a_z", "w_x", "w_y", "w_z"]);
}
function onMessage(evt)
{
	var msg   = JSON.parse(evt.data);
	var event = msg.mEvent;
	var time  = msg.mTime;	
	var data  = msg.mData;
	switch(event)
	{
		case "Sensor1Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor1Plot.addData(sensorData);
			break;
		case "Sensor2Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor2Plot.addData(sensorData);
			break;
		case "Sensor3Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor3Plot.addData(sensorData);
			break;
		case "Sensor4Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor4Plot.addData(sensorData);
			break;
		case "Sensor5Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor5Plot.addData(sensorData);
			break;
		case "Sensor6Data":
			var sensorData = [time, data.mA_x, data.mA_y, data.mA_z, data.mW_x, data.mW_y, data.mW_z];
			gSensor6Plot.addData(sensorData);
			break;
	}	
}
function onConnectClicked()
{
	if(gWebSocket.isOpen())
	{
		gWebSocket.close();
		document.getElementById("ConnectButtonID").innerHTML = "Connect";
	}
	else
	{
		gWebSocket.init();
		document.getElementById("ConnectButtonID").innerHTML = "Disconnect";
	}
}
