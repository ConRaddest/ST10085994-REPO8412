%% Loading Data From CSV File

clear; clc;
% Load the data from the CSV file
data = readtable('irradiance_data_2023.csv'); % Replace 'irradiance_data_2023.csv' with the actual filename

% Convert period_end column to datetime format
data.period_end = datetime(data.period_end, 'InputFormat', 'yyyy-MM-dd''T''HH:mm:ss+00:00', 'TimeZone', 'UTC');

% Filter data for the first 7 days
start_time = data.period_end(1);
end_time = start_time + days(1);
first_week_data = data(data.period_end >= start_time & data.period_end < end_time, :);

% Extract relevant columns for the first 7 days
G_data = first_week_data.ghi;
T_data = first_week_data.air_temp;

%% Divide into 90/10 Split for Training & Testing
N_G = floor(0.9*numel(G_data));

g_train = G_data(1:N_G+1);
g_test = G_data(N_G+1:end);

%% Standardise for model training
mu_g = mean(g_train);
sig_g = std(g_train);

g_train_standardised = (g_train - mu_g) / sig_g;

%% Prepare Predictors and Responses
x_g_train = num2cell(g_train_standardised(1:end-1)); % Cell array for predictors
y_g_train = num2cell(g_train_standardised(2:end));   % Cell array for responses

%% Define LSTM Architecture
num_features = 1;
num_responses = 1;
num_hidden_units = 200;

layers = [
    sequenceInputLayer(num_features)
    lstmLayer(num_hidden_units)
    fullyConnectedLayer(num_responses)
    regressionLayer]; % Add regression layer as output layer

options = trainingOptions("adam", ...
    MaxEpochs=250, ...
    GradientThreshold=1, ...
    InitialLearnRate=0.005, ...
    LearnRateSchedule='piecewise', ...
    LearnRateDropPeriod=125, ...
    LearnRateDropFactor=0.2, ...
    Verbose=0, ...
    Plots='training-progress');

%% Train Neural Network
net_g = trainNetwork(x_g_train, y_g_train, layers, options);

%% Forecast Future Time Steps
g_test_standardised = (g_test - mu_g) / sig_g;

x_g_test = num2cell(g_test_standardised(1:end-1)); % Cell array for predictors

y_g_train = num2cell(g_train_standardised(2:end));   % Cell array for responses

