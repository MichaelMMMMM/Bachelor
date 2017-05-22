%-------------------------------------------------------------------------%
% 03.04.2017, Michael Meindl                                              %
% Function to create a customized plot legend.                            %
% The first parameter is a cell holding the legend entries.               %
% The second parameter is a string specifying the legend position         %
% 'ne': northeast; "nw" : northwest; "se": southeast, "sw": southwest     %
%-------------------------------------------------------------------------%
function [ emllegend ] = emlLegend( legendEntriesCell , location)
    if (nargin < 2)
        location = 'nw';
    end
    emllegend = legend(legendEntriesCell, 'interpreter', 'latex',...
                       'FontSize', 14, 'Location', location);
end

