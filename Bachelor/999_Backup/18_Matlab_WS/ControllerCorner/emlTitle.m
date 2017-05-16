function [ ret ] = emlTitle(titlestring )
ret = title(titlestring, 'interpreter', 'latex', 'FontSize', 20, 'FontWeight', 'bold');
end

