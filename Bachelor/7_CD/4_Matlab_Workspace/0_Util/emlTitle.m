%-------------------------------------------------------------------------%
% 03.04.2017, Michael Meindl                                              %
% Function to create a customized plot title.                             %
% The first parameter is the title string.                                %
%-------------------------------------------------------------------------%
function [ ret ] = emlTitle(titlestring )
    ret = title(titlestring, 'interpreter', 'latex', 'FontSize', 20, 'FontWeight', 'bold');
end

