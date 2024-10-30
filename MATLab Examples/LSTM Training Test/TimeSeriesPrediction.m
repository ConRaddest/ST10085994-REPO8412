%% ---------------------------- init Variabels ----------------------------
clc; clear; close all;

opt.Delays = [1 2 3 4 5 6 7 8 9 10 12 16 20];
opt.dataPreprocessMode  = 'Data Standardization'; % 'None' 'Data Standardization' 'Data Normalization'
opt.learningMethod      = 'LSTM';                 % 'MLP' 'LSTM'    
opt.trPercentage        = 0.8;                    %  divide data into Test  and Train dataset

% ------------- BILSTM parameters 
opt.NumOfHiddenLayers = 2;                        %  number of (bi)LSTM layers

opt.NumOfUnitsInFirstlayer  = 125;                %  number of (bi)LSTM units in the first  layer
opt.NumOfUnitsInSecondlayer = 100;                %  number of (bi)LSTM units in the second layer
opt.NumOfUnitsInThirdlayer  = 75;                 %  number of (bi)LSTM units in the third  layer
opt.NumOfUnitsInFourthlayer = 75;                 %  number of (bi)LSTM units in the forth  layer

opt.isUseBiLSTMLayer  = true;                    % if it is true the layer turn to the Bidirectional-LSTM and if it is false it will turn the units to the simple LSTM
opt.isUseDropoutLayer = false;                    % dropout layer avoid of bieng overfit
opt.DropoutValue      = 0.5;

opt.maxEpochs     = 200;                          % maximum number of training Epoch in bi-LSTM.
opt.miniBatchSize = 32;                          % minimum batch size in bi-LSTM .
opt.executionEnvironment = 'gpu';                % 'cpu' 'gpu' 'auto'
opt.LR                   = 'adam';               % 'sgdm' 'rmsprop' 'adam'
opt.trainingProgress     = 'training-progress';  % 'training-progress' 'none'.

% MLP parameters
opt.NumOfFeedForwardLeyars = 2;

opt.NumOfNeuronsInFirstlayer  = 15;         %  number of neurons in the first  layer
opt.NumOfNeuronsInSecondlayer = 15;         %  number of neurons in the second layer
opt.NumOfNeuronsInThirdlayer  = 10;         %  number of neurons in the third  layer

opt.trainFcn = 'trainbr';                   % 'trainlm' 'trainscg' 'traincgf' 'trainbr'
opt.maxItrations = 100;                     % maximum number of training itration.
opt.showWindow             = true;          % display training window.
opt.showCommandLine        = true;          % display training process on workspace.

opt.isSavePredictedData    = true;         %  save output prediction on an excel file

%% --------------- load Data
data = loadData(opt);
if ~data.isDataRead
    return;
end
%% --------------- Train Network
[opt,data] = TrainData(opt,data);

%% --------------- Evaluate Data 
[opt,data] = EvaluationData(opt,data);
%% --------------- Save Training Network as a File
Net = data.BiLSTM.Net;
save('NET_30day_5min_irradiance','Net')
%% --------------- Save Source Signal
irradiance_data = data.seriesdata(1:288)';
plot(irradiance_data)

%% 
save('30day_5min_irradiance', 'irradiance_data')

%% ---------------------------- Local Functions ---------------------------
function data = loadData(opt)
 [chosenfile,chosendirectory] = uigetfile({'*.xlsx';'*.csv'},...
                       'Select Excel time series Data sets','data.xlsx');
   filePath = [chosendirectory chosenfile];
    if filePath ~= 0 
        data.DataFileName = chosenfile;
        data.CompleteData = readtable(filePath); 
        if size(data.CompleteData,2)>1
             warning('Input data should be an excel file with only one column!'); 
             disp('Operation Failed... '); pause(.9);
             disp('Reloading data. ');     pause(.9);
             data.x = [];
             data.isDataRead = false;
             return;
        end
        data.seriesdataHeder = data.CompleteData.Properties.VariableNames(1,:);
        data.seriesdata = table2array(data.CompleteData(:,:));
        disp('Input data successfully read.');
        data.isDataRead = true;
        data.seriesdata = PreInput(data.seriesdata);
        
        figure('Name','InputData','NumberTitle','off');
        plot(data.seriesdata);
        title({['Mean = ' num2str(mean(data.seriesdata)) ', STD = ' num2str(std(data.seriesdata)) ];});
        if strcmpi(opt.dataPreprocessMode,'None')
            data.x = data.seriesdata;
        elseif strcmpi(opt.dataPreprocessMode,'Data Normalization')
            data.x = DataNormalization(data.seriesdata);
            figure('Name','NormilizedInputData','NumberTitle','off');
            plot(data.x); grid minor;
            title({['Mean = ' num2str(mean(data.x)) ', STD = ' num2str(std(data.x)) ];});
        elseif strcmpi(opt.dataPreprocessMode,'Data Standardization')
            data.x = DataStandardization(data.seriesdata);
            figure('Name','NormilizedInputData','NumberTitle','off');
            plot(data.x); grid minor;
            title({['Mean = ' num2str(mean(data.x)) ', STD = ' num2str(std(data.x)) ];});
        end
        
    else 
        warning(['In order to train network, please load data.' ...
        'Input data should be an excel file with only one column!']);    
        disp('Operation Cancel.'); 
        data.isDataRead = false;
    end
end
function data = PreInput(data)
    if iscell(data)
        for i=1:size(data,1)
            for j=1:size(data,2)
                if strcmpi(data{i,j},'#NULL!')
                    tempVars(i,j) = NaN; %#ok
                else
                    tempVars(i,j) = str2num(data{i,j});   %#ok
                end
            end
        end
        data = tempVars;
    end

end
function  vars = DataStandardization(data)
    for i=1:size(data,2)
        x.mu(1,i)   = mean(data(:,i),'omitnan');
        x.sig(1,i)  = std (data(:,i),'omitnan');
        vars(:,i) = (data(:,i) - x.mu(1,i))./ x.sig(1,i);
    end
end
function vars = DataNormalization(data)
    for i=1:size(data,2)
        vars(:,i) = (data(:,i) -min(data(:,i)))./ (max(data(:,i))-min(data(:,i)));
    end
end
% --------------- Train Network ---------------
% ---------------------------------------------
function [opt,data] = TrainData(opt,data)
% Bi-LSTM parameters
if opt.NumOfHiddenLayers ==1
    opt.numHiddenUnits1 = opt.NumOfUnitsInFirstlayer;   
elseif opt.NumOfHiddenLayers ==2
    opt.numHiddenUnits1 = opt.NumOfUnitsInFirstlayer; 
    opt.numHiddenUnits2 = opt.NumOfUnitsInSecondlayer;    
elseif opt.NumOfHiddenLayers ==3
    opt.numHiddenUnits1 = opt.NumOfUnitsInFirstlayer; 
    opt.numHiddenUnits2 = opt.NumOfUnitsInSecondlayer;  
    opt.numHiddenUnits3 = opt.NumOfUnitsInThirdlayer; 
elseif opt.NumOfHiddenLayers ==4
    opt.numHiddenUnits1 = opt.NumOfUnitsInFirstlayer; 
    opt.numHiddenUnits2 = opt.NumOfUnitsInSecondlayer;  
    opt.numHiddenUnits3 = opt.NumOfUnitsInThirdlayer; 
    opt.numHiddenUnits4 = opt.NumOfUnitsInFourthlayer; 
end
% MLP parameters
if opt.NumOfFeedForwardLeyars ==1
    opt.ShallowhiddenLayerSize = [opt.NumOfNeuronsInFirstlayer];                                       % number of Hidden layers in MLP network.
elseif opt.NumOfFeedForwardLeyars ==2
    opt.ShallowhiddenLayerSize = [opt.NumOfNeuronsInFirstlayer opt.NumOfNeuronsInSecondlayer];          % number of Hidden layers in MLP network. 
elseif opt.NumOfFeedForwardLeyars ==3
    opt.ShallowhiddenLayerSize = [opt.NumOfNeuronsInFirstlayer opt.NumOfNeuronsInSecondlayer opt.NumOfNeuronsInThirdlayer];% number of Hidden layers in MLP network.
end



% prepare delays for time serie network
data = CreateTimeSeriesData(opt,data);

% divide data into test and train data
data = dataPartitioning(opt,data);

if strcmpi(opt.learningMethod,'LSTM')
    % LSTM data form
    data = LSTMInput(data);
    %  Define LSTM  architect 
    opt = LSTMArchitect(opt,data);
elseif strcmpi(opt.learningMethod,'MLP')
    % Prepare input data for MLP network.
    FeedForwardInput();
    %  Define MLP architect 
    opt  = FeedForwardArchitect(opt);    
end

% Train LSTM, MLP 
data = TrainNet(opt,data);

end
% make some delays on input filed
function data = CreateTimeSeriesData(opt,data)
    Delays = opt.Delays;

    x = data.x';
    T = size(x,2);
    
    MaxDelay = max(Delays);
    
    Range = MaxDelay+1:T;
    
    X= [];
    for d = Delays
        X=[X; x(:,Range-d)];
    end
    
    Y = x(:,Range);
    data.X  = X;
    data.Y  = Y;
end
% partitioning input data 
function data = dataPartitioning(opt,data)
data.XTr   = [];
data.YTr   = [];
data.XTs   = [];
data.YTs   = [];

numTrSample = round(opt.trPercentage*size(data.X,2));

data.XTr   = data.X(:,1:numTrSample);
data.YTr   = data.Y(:,1:numTrSample);

data.XTs   = data.X(:,numTrSample+1:end);
data.YTs   = data.Y(:,numTrSample+1:end);

disp(['Time Series data divided to ' num2str(opt.trPercentage*100) '% Train data and ' num2str((1-opt.trPercentage)*100) '% Test data']);
end
% Prepare input data for MLP network.
function FeedForwardInput()
    disp('Time Series data prepared as suitable MLP Input data.');
end
% Prepare input data for LSTM network.
function data = LSTMInput(data)

for i=1:size(data.XTr,2)
    XTr{i,1} = data.XTr(:,i);  
    YTr(i,1) = data.YTr(:,i);  
end

for i=1:size(data.XTs,2)
    XTs{i,1} =  data.XTs(:,i);  
    YTs(i,1) =  data.YTs(:,i); 
end
data.XTr   = XTr;
data.YTr   = YTr;
data.XTs   = XTs;
data.YTs   = YTs;

disp('Time Series data prepared as suitable LSTM Input data.');
end

% ---- network structure ----
% bi-LSTM Deeplearning Architect
function opt = LSTMArchitect(opt,data)

miniBatchSize   = opt.miniBatchSize;
maxEpochs       = opt.maxEpochs;
trainingProgress = opt.trainingProgress;
executionEnvironment = opt.executionEnvironment;

inputSize = size(data.X,1);
outputMode = 'last';
numResponses   = 1;
dropoutVal = opt.DropoutValue;
if opt.isUseDropoutLayer % if dropout layer is true
    if opt.NumOfHiddenLayers ==1
        if opt.isUseBiLSTMLayer == 1
            opt.layers = [ ...
                sequenceInputLayer(inputSize)
                bilstmLayer(opt.numHiddenUnits1,'OutputMode',outputMode)
                dropoutLayer(dropoutVal)
                fullyConnectedLayer(numResponses)
                regressionLayer];
        else
            opt.layers = [ ...
                sequenceInputLayer(inputSize)
                lstmLayer(opt.numHiddenUnits1,'OutputMode',outputMode)
                dropoutLayer(dropoutVal)
                fullyConnectedLayer(numResponses)
                regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==2
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits2,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            lstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            lstmLayer(opt.numHiddenUnits2,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==3
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits3,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits3,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==4
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits3,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits4,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits3,'OutputMode','sequence')
            dropoutLayer(dropoutVal)
            bilstmLayer(opt.numHiddenUnits4,'OutputMode',outputMode)
            dropoutLayer(dropoutVal)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    end
else % if dropout layer is false
    if opt.NumOfHiddenLayers ==1
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
                sequenceInputLayer(inputSize)
                bilstmLayer(opt.numHiddenUnits1,'OutputMode',outputMode)
                fullyConnectedLayer(numResponses)
                regressionLayer];
        else
            opt.layers = [ ...
                sequenceInputLayer(inputSize)
                lstmLayer(opt.numHiddenUnits1,'OutputMode',outputMode)
                fullyConnectedLayer(numResponses)
                regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==2
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits2,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            lstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            lstmLayer(opt.numHiddenUnits2,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==3
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits3,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits3,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    elseif opt.NumOfHiddenLayers ==4
        if opt.isUseBiLSTMLayer
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits3,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits4,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        else
            opt.layers = [ ...
            sequenceInputLayer(inputSize)
            bilstmLayer(opt.numHiddenUnits1,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits2,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits3,'OutputMode','sequence')
            bilstmLayer(opt.numHiddenUnits4,'OutputMode',outputMode)
            fullyConnectedLayer(numResponses)
            regressionLayer];
        end
    end
end
% Training Network Options
% 'sgdm' 
% 'rmsprop'
% 'adam'

opt.opts = trainingOptions(opt.LR, ...
    'MaxEpochs',maxEpochs, ...
    'GradientThreshold',1, ...
    'InitialLearnRate',0.05, ...
    'LearnRateSchedule','piecewise', ...
    'LearnRateDropPeriod',125, ...
    'LearnRateDropFactor',0.2, ...
    'Verbose',1, ...
    'MiniBatchSize',miniBatchSize,...
    'ExecutionEnvironment',executionEnvironment,...
    'Plots',trainingProgress);
    disp('LSTM architect successfully created.');
end
% MLP Shallowlearning Architect
function opt = FeedForwardArchitect(opt)
opt.Net = feedforwardnet(opt.ShallowhiddenLayerSize,opt.trainFcn);
opt.Net.divideParam.trainRatio = 80/100;
opt.Net.divideParam.valRatio  = 10/100;
opt.Net.divideParam.testRatio = 10/100;

opt.Net.trainParam.epochs          = opt.maxItrations;
opt.Net.trainParam.showWindow      = opt.showWindow;
opt.Net.trainParam.showCommandLine = opt.showCommandLine;
disp('MLP architect successfully created.');

end
% Train  Network
function data = TrainNet(opt,data)

if strcmpi(opt.learningMethod,'LSTM')
    try
        data.BiLSTM.Net = trainNetwork(data.XTr,data.YTr,opt.layers,opt.opts);
        disp('LSTM Netwwork successfully trained.');
        data.IsNetTrainSuccess =true;
    catch me
        disp('Error on Training LSTM Network');
        data.IsNetTrainSuccess = false;
        return;
    end
elseif strcmpi(opt.learningMethod,'MLP')
    try
        [data.FF.Net,~] = train(opt.Net,data.XTr,data.YTr);
        disp('Feed Forward Netwwork successfully trained.');
        data.IsNetTrainSuccess = true;
    catch me
        disp('Error on Training FF Network');
        data.IsNetTrainSuccess =false;
        return;
    end
end

end


% --------------- Evaluate Data ---------------
% ---------------------------------------------
function [opt,data] = EvaluationData(opt,data)
if strcmpi(opt.learningMethod,'LSTM')
    
    data.BiLSTM.TrainOutputs = deNorm(data.seriesdata,predict(data.BiLSTM.Net,data.XTr,'MiniBatchSize',opt.miniBatchSize),opt.dataPreprocessMode);
    data.BiLSTM.TrainTargets = deNorm(data.seriesdata,data.YTr,opt.dataPreprocessMode);
    data.BiLSTM.TestOutputs  = deNorm(data.seriesdata,predict(data.BiLSTM.Net,data.XTs,'MiniBatchSize',opt.miniBatchSize),opt.dataPreprocessMode);
    data.BiLSTM.TestTargets  = deNorm(data.seriesdata,data.YTs,opt.dataPreprocessMode);
    data.BiLSTM.AllDataTargets = [data.BiLSTM.TrainTargets data.BiLSTM.TestTargets];
    data.BiLSTM.AllDataOutputs = [data.BiLSTM.TrainOutputs data.BiLSTM.TestOutputs];
   
    data = PlotResults(data,'Tr',...
        data.BiLSTM.TrainOutputs, ...
        data.BiLSTM.TrainTargets);
    data = plotReg(data,'Tr',data.BiLSTM.TrainTargets,data.BiLSTM.TrainOutputs);

    data = PlotResults(data,'Ts',....
        data.BiLSTM.TestOutputs, ...
        data.BiLSTM.TestTargets);
    data = plotReg(data,'Ts',data.BiLSTM.TestTargets,data.BiLSTM.TestOutputs);

    data = PlotResults(data,'All',...
        data.BiLSTM.AllDataOutputs, ...
        data.BiLSTM.AllDataTargets);
    data = plotReg(data,'All',data.BiLSTM.AllDataTargets,data.BiLSTM.AllDataOutputs);
    
    disp('Bi-LSTM network performance evaluated.');
    
elseif strcmpi(opt.learningMethod,'MLP')
    
        data.FF.TrainOutputs = deNorm(data.seriesdata,data.FF.Net(data.XTr)',opt.dataPreprocessMode);
        data.FF.TrainTargets = deNorm(data.seriesdata,(data.YTr)',opt.dataPreprocessMode);
        data.FF.TestOutputs  = deNorm(data.seriesdata,data.FF.Net(data.XTs)',opt.dataPreprocessMode);
        data.FF.TestTargets  = deNorm(data.seriesdata,(data.YTs)',opt.dataPreprocessMode);

    data.FF.AllDataTargets = [data.FF.TrainTargets data.FF.TestTargets];
    data.FF.AllDataOutputs = [data.FF.TrainOutputs data.FF.TestOutputs];
 
    DispVal = 1;
    for i= DispVal
        data = PlotResults(data,'Tr',...
            data.FF.TrainOutputs(i,:), ...
            data.FF.TrainTargets(i,:));
        data = plotReg(data,'Tr',data.FF.TrainTargets(i,:),data.FF.TrainOutputs(i,:));
        data = PlotResults(data,'Ts',....
            data.FF.TestOutputs(i,:), ...
            data.FF.TestTargets(i,:));
        data = plotReg(data,'Ts',data.FF.TestTargets(i,:),data.FF.TestOutputs(i,:));
        data = PlotResults(data,'All',...
            data.FF.AllDataOutputs(i,:), ...
            data.FF.AllDataTargets(i,:));
        data = plotReg(data,'All',data.FF.AllDataTargets(i,:),data.FF.AllDataOutputs(i,:));
        disp('MLP network performance evaluated.');
    end

end
end
function vars = deNorm(data,stdData,deNormMode)
if iscell(stdData(1,1))
        for i=1:size(stdData,1)
            tmp(i,:) = stdData{i,1}';
        end
        stdData = tmp;
end
if strcmpi(deNormMode,'Data Normalization')
    for i=1:size(data,2)
        vars(:,i) = (stdData(:,i).*(max(data(:,i))-min(data(:,i)))) + min(data(:,i));
    end
    vars = vars';
    
elseif strcmpi(deNormMode,'Data Standardization')
    for i=1:size(data,2)
        x.mu(1,i)   = mean(data(:,i),'omitnan');
        x.sig(1,i)  = std (data(:,i),'omitnan');
        vars(:,i) = ((stdData(:,i).* x.sig(1,i))+ x.mu(1,i));
    end
    vars = vars';
    
else
    vars = stdData';
    return;
end
end
% plot the output of networks and real output on test and train data
function data = PlotResults(data,firstTitle,Outputs,Targets)  
Errors = Targets - Outputs;
    MSE   = mean(Errors.^2);
    RMSE  = sqrt(MSE);
    NRMSE = RMSE/mean(Targets);
    ErrorMean = mean(Errors);
    ErrorStd  = std(Errors);
    rankCorre = RankCorre(Targets,Outputs);

    if strcmpi(firstTitle,'tr')
         Disp1Name = 'OutputGraphEvaluation_TrainData';
         Disp2Name = 'ErrorEvaluation_TrainData';
         Disp3Name = 'ErrorHistogram_TrainData';
    elseif strcmpi(firstTitle,'ts')
        Disp1Name = 'OutputGraphEvaluation_TestData';
        Disp2Name = 'ErrorEvaluation_TestData';
        Disp3Name = 'ErrorHistogram_TestData';
    elseif strcmpi(firstTitle,'all')
        Disp1Name = 'OutputGraphEvaluation_ALLData';
        Disp2Name = 'ErrorEvaluation_ALLData';
        Disp3Name = 'ErrorHistogram_AllData';
    end
    
    figure('Name',Disp1Name,'NumberTitle','off');
    plot(1:length(Targets),Targets,...
        1:length(Outputs),Outputs);grid minor
    legend('Targets','Outputs','Location','best') ;
    title(['Rank Correlation = ' num2str(rankCorre)]);
   
    figure('Name',Disp2Name,'NumberTitle','off');
    plot(Errors);grid minor
    title({['MSE = ' num2str(MSE) ', RMSE = ' num2str(RMSE)...
        ' NRMSE = ' num2str(NRMSE)] ;});
    xlabel(['Error Per Sample']);
 
    figure('Name',Disp3Name,'NumberTitle','off');
    histogram(Errors);grid minor

    title(['Error Mean = ' num2str(ErrorMean) ', Error StD = ' num2str(ErrorStd)]);
    xlabel(['Error Histogram']);
    
    if strcmpi(firstTitle,'tr')
        data.Err.MSETr = MSE;
        data.Err.STDTr = ErrorStd;
        data.Err.NRMSETr     = NRMSE;
        data.Err.rankCorreTr = rankCorre;
    elseif strcmpi(firstTitle,'ts')
        data.Err.MSETs = MSE;
        data.Err.STDTs = ErrorStd;
        data.Err.NRMSETs     = NRMSE;
        data.Err.rankCorreTs = rankCorre;
    elseif strcmpi(firstTitle,'all')
        data.Err.MSEAll = MSE;
        data.Err.STDAll = ErrorStd;
        data.Err.NRMSEAll     = NRMSE;
        data.Err.rankCorreAll = rankCorre;
    end
end
% find rank correlation between network output and real data
function [r]=RankCorre(x,y)
x=x';
y=y';
% Find the data length
N = length(x);
% Get the ranks of x
R = crank(x)';
for i=1:size(y,2)
    % Get the ranks of y
    S = crank(y(:,i))';
    % Calculate the correlation coefficient
    r(i) = 1-6*sum((R-S).^2)/N/(N^2-1); %#ok
end
end
function r=crank(x)
u = unique(x);
[~,z1] = sort(x);
[~,z2] = sort(z1);
r = (1:length(x))';
r=r(z2);
for i=1:length(u)
    s=find(u(i)==x);
    r(s,1) = mean(r(s));
end
end
% plot the regression line of output and real value
function data = plotReg(data,Title,Targets,Outputs)

 if strcmpi(Title,'tr')
     DispName = 'RegressionGraphEvaluation_TrainData';
elseif strcmpi(Title,'ts')
    DispName = 'RegressionGraphEvaluation_TestData';
elseif strcmpi(Title,'all')
    DispName = 'RegressionGraphEvaluation_ALLData';
end
figure('Name',DispName,'NumberTitle','off');
x = Targets';
y = Outputs';
format long
b1 = x\y;
yCalc1 = b1*x;
scatter(x,y,'MarkerEdgeColor',[0 0.4470 0.7410],'LineWidth',.7);
hold('on');
plot(x,yCalc1,'Color',[0.8500 0.3250 0.0980]);
xlabel('Prediction');
ylabel('Target');
grid minor
% xgrid = 'on';
% disp.YGrid = 'on';
X = [ones(length(x),1) x];
b = X\y;
yCalc2 = X*b;
plot(x,yCalc2,'-.','MarkerSize',4,"LineWidth",.1,'Color',[0.9290 0.6940 0.1250])
legend('Data','Fit','Y=T','Location','best');
%
Rsq2 = 1 -  sum((y - yCalc1).^2)/sum((y - mean(y)).^2);

if strcmpi(Title,'tr')
    data.Err.RSqur_Tr = Rsq2;
    title(['Train Data, R^2 = ' num2str(Rsq2)]);
elseif strcmpi(Title,'ts')
    data.Err.RSqur_Ts = Rsq2;
    title(['Test Data, R^2 = ' num2str(Rsq2)]);
elseif strcmpi(Title,'all')
    data.Err.RSqur_All = Rsq2;
    title(['All Data, R^2 = ' num2str(Rsq2)]);
end

end

