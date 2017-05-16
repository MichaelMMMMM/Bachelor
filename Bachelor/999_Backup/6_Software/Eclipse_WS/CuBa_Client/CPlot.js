function CPlot(placeholder, nbrOfLines, labels)
{
	this.mPlaceHolder = placeholder;
	this.mNbrOfLines  = nbrOfLines;
	this.mTime		  = [0];
	this.mData		  = [];
	this.mDisplayData	  = [];
	this.mDataLength  = 1;
	this.mPlotCounter = 0;
	for(var i = 0; i < nbrOfLines; i++)
	{
		this.mData.push( { label: labels[i],
						   data: [],
						   shadowSize: 0
						 });
	};
	
	$.plot("#"+this.mPlaceHolder, this.mData);
}
CPlot.prototype.addData = function(data)
{
	this.mTime.push(data[0]);
	for(var i = 0; i < this.mNbrOfLines; i++) 
	{
		this.mData[i].data.push([ data[0], data[i+1] ]);
	}
	this.mPlotCounter = this.mPlotCounter + 1;
	if(this.mPlotCounter >= 5)
	{
		if(this.mTime.length > 500)
		{
			this.mDisplayData = [];
			for(var i = 0; i < this.mNbrOfLines; i++)
			{
				this.mDisplayData.push( { label: this.mData[i].label,
							  data:  this.mData[i].data.slice(this.mTime.length - 501, this.mTime.length-1),
							  shadowSize: 0 } );
			}
		}
		else
		{
			this.mDisplayData = this.mData;
		}
		this.mPlotCounter = 0;
		$.plot("#"+this.mPlaceHolder, this.mDisplayData);
	}
};
