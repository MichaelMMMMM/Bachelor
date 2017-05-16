function [ h ] = emlFigure()
set(0,'defaulttextinterpreter', 'latex');
figure; h = get(gca);
h.XLabel.FontSize = 14;
h.XLabel.FontWeight = 'bold';
h.YLabel.FontSize = 14;
h.YLabel.FontWeight = 'bold';
h.Title.FontSize  = 21;
h.Title.FontWeight = 'bold';
end

