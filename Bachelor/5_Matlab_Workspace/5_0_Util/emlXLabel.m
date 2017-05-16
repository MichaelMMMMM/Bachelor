%-------------------------------------------------------------------------%
% 03.04.2017, Michael Meindl                                              %
% Function to create a customized label on the x-axis.                    %
% The first parameter is the label-string                                 %
%-------------------------------------------------------------------------%
function [ xLabel ] = emlXLabel(label)
    xLabel = xlabel(label, 'interpreter', 'latex', 'FontSize', 16, 'FontWeight', 'bold');
end

