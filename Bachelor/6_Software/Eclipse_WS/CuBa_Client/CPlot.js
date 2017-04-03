function CPlot(placeholder, nbrOfLines, labels)
{
	this.mPlaceHolder = placeholder;
	this.mNbrOfLines  = nbrOfLines;
	this.mTime		  = [0];
	this.mData		  = [];
	this.mDataLength  = 1;
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
	$.plot("#"+this.mPlaceHolder, this.mData);
};
