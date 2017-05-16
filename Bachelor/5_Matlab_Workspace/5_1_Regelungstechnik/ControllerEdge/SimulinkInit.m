%-------------------------------------------------------------------------%
% 03.04.2017, Michael Meindl                                              %
% Script to initialize all required parameters for the simulation.        %
%-------------------------------------------------------------------------%

ParameterInit;
ControllerDesign;

% Initial system state
x_0      = [0.07; 0; 0];
% Simulated measurement offset
x_offset = [0.01; 0; 0];
% Noise-Power of the simulated measurement error
y_noise  = [0.000001668252765; 0.000000092522909; 0.256493601424753];

