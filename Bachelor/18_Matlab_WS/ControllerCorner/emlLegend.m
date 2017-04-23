function [ emllegend ] = emlLegend( legendEntriesCell )
emllegend = legend(legendEntriesCell, 'interpreter', 'latex',...
                   'FontSize', 14, 'Location', 'nw');
end

