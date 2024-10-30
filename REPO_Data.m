
% Short Circuit and Max Current as per Panel Standard Conditions
Isc = 8.21;
Imps = 7.61;

% Open Circuit and Max Voltage as per Panel Standard Conditions
Voc = 32.9;
Vmps = 26.3;

% Current and Voltage Temp Coefficients as per Manufactorer
alpha = 3.18e-3;
beta = -1.23e-1;

% Irradiance Values
Gmin = 0;
Gmax = 1000;
Gs = 1000;

% Temperature Values
Tmin = 5;
Tmax = 45;
Ts = 25;

for i = 1:10000
    % Generating Random Temperature and Irradiance
    T = (Tmax-Tmin)*rand + Tmin;
    G = (Gmax-Gmin)*rand + Gmin;
    
    % Calculating Current, Voltage and Power @ Given Conditions
    Impp(i) = Imps * (G/Gs) * (1 + (alpha * (T-Ts)));
    Vmpp(i) = Vmps + (beta * (T-Ts));
    Pmpp(i) = Impp(i) * Vmpp(i);

    % Assigning to Input & Output for Neural Network Training
    input(i, :) = [G T];

    outputV(i, 1) = Vmpp(i);
    outputI(i, 1) = Impp(i);
    outputP(i, 1) = Pmpp(i);
end
