clear; clc;
% Load the data from the CSV file
data = readtable('irradiance_data_2023.csv'); % Replace 'irradiance_data_2023.csv' with the actual filename

% Convert period_end column to datetime format
data.period_end = datetime(data.period_end, 'InputFormat', 'yyyy-MM-dd''T''HH:mm:ss+00:00', 'TimeZone', 'UTC');

% Filter data for the first 7 days
start_time = data.period_end(1);
end_time = start_time + days(7);
first_week_data = data(data.period_end >= start_time & data.period_end < end_time, :);

% Extract relevant columns for the first 7 days
ghi = first_week_data.ghi;
air_temp = first_week_data.air_temp;
time = first_week_data.period_end;

% Generate new time vector at 100ms intervals for the first 7 days
time_100ms = (start_time:milliseconds(100):end_time)';

% Interpolate GHI and Air Temperature to 100ms intervals using spline interpolation for GHI and linear for temperature
ghi_100ms = interp1(time, ghi, time_100ms, 'spline');
air_temp_100ms = interp1(time, air_temp, time_100ms, 'linear');

% Combine interpolated GHI and temperature data into a matrix
data_combined = [ghi_100ms, air_temp_100ms];

% Define the sequence length (e.g., 1 hour in 100ms intervals = 36000 steps)
sequenceLength = 36000; % Adjust as needed for your use case

% Split data into sequences of defined length
numSequences = floor(size(data_combined, 1) / sequenceLength);
dataSequences = cell(numSequences, 1);

for i = 1:numSequences
    startIdx = (i - 1) * sequenceLength + 1;
    endIdx = i * sequenceLength;
    dataSequences{i} = data_combined(startIdx:endIdx, :);
end

% Split sequences into predictors (XTrain) and targets (TTrain)
numObservationsTrain = numel(dataSequences);
XTrain = cell(numObservationsTrain, 1);
TTrain = cell(numObservationsTrain, 1);

for n = 1:numObservationsTrain
    X = dataSequences{n};
    XTrain{n} = X(1:end-1, :); % Predictor sequence (omit last time step)
    TTrain{n} = X(2:end, :);   % Target sequence (shifted by one time step)
end

% Calculate the per-channel mean and standard deviation values for XTrain and TTrain
muX = mean(cell2mat(XTrain), 1); % Compute mean per channel (GHI and temp)
sigmaX = std(cell2mat(XTrain), 0, 1); % Compute standard deviation per channel

muT = mean(cell2mat(TTrain), 1); % Compute mean per channel (GHI and temp)
sigmaT = std(cell2mat(TTrain), 0, 1); % Compute standard deviation per channel

% Normalize the sequences using the calculated mean and standard deviation values
for n = 1:numel(XTrain)
    XTrain{n} = (XTrain{n} - muX) ./ sigmaX; % Normalize predictors
    TTrain{n} = (TTrain{n} - muT) ./ sigmaT; % Normalize targets
end

% Display normalized training data for confirmation
fprintf('Mean of normalized XTrain (should be close to 0):\n');
disp(mean(cell2mat(XTrain)));

fprintf('Standard deviation of normalized XTrain (should be close to 1):\n');
disp(std(cell2mat(XTrain)));

fprintf('Mean of normalized TTrain (should be close to 0):\n');
disp(mean(cell2mat(TTrain)));

fprintf('Standard deviation of normalized TTrain (should be close to 1):\n');
disp(std(cell2mat(TTrain)));
