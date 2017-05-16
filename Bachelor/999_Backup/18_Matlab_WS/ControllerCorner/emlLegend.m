function [ emllegend ] = emlLegend( legendEntriesCell , location)
if (nargin < 2)
    location = 'nw';
end
emllegend = legend(legendEntriesCell, 'interpreter', 'latex',...
                   'FontSize', 14, 'Location', location);
end

