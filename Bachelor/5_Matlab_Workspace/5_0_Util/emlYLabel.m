%-------------------------------------------------------------------------%
% 03.04.2017, Michael Meindl                                              %
% Function to create a customized label on the y-axis.                    %
% The first parameter is the label-string                                 %
%-------------------------------------------------------------------------%
function [ ret ] = emlYLabel( label )
    ret = ylabel(label, 'interpreter', 'latex', 'FontSize', 16, 'FontWeight', 'bold');
end

