function CTestHandler()
{
	this.mTestPlot = new CPlot("placeholder", 2, ["phi1", "phi2"]);
	var jsonData = JSON.parse('{"time":7.72,"phi1":0.991038,"phi2":0.133581}');
	this.mTestPlot.addData([jsonData.time, jsonData.phi1, jsonData.phi2]);
	
	this.dummy = function()
	{
		var data = [0,1,2];
		this.mTestPlot.addData(data);
	};
	this.handleMessage = function(evt)
	{
		this.dummy();
		var jsonData = JSON.parse(evt.data);
		var plotData = [jsonData.time, jsonData.phi1, jsonData.phi2];
		this.mTestPlot.addData(plotData);
	};
};
