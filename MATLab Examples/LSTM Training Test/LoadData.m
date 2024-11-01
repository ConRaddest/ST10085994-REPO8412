function [data] = LoadData(data,opt,mode)
warning off;

[chosenfile,chosendirectory] = uigetfile({'*.xlsx';'*.csv'},...
    ['Select Excel ' mode ' Data sets'],'data.xlsx');
filePath = [chosendirectory,chosenfile];
if chosenfile==0
    disp('Data is not loaded!');
    data.isDataRead   = false;
    return;
end
indx=1;
[status,sheets,xlFormat] = xlsfinfo(filePath);
if ~strcmpi(status,'Microsoft Excel Spreadsheet')
    warning('please load a correct Microsoft Excel file.');
end
if length(sheets)>1
    for ii=1:length(sheets)
        tempData{ii} = xlsread(filePath,ii,'','','');
    end
    if sum(cellfun(@(x) ~isempty(x),tempData))>1  % it means we have more than one page
        fn = sheets;
        Opt.filename = 'Select Sheet';
        Opt.str = [{'The Microsoft Excel file contains more than one page.'} {'please select your target Sheet.' }];
        Opt.list = fn;
        indx = evalin("base",'selectedSheet');
        if isempty(indx)
            indx=1;
        end
    end
end
[num,txt,raw] = xlsread(filePath,indx,'','','');
CompleteData  = readtable(filePath,'Sheet', indx);
if size(raw,2)==0 % check if raw is empty
    if size(num,2)==size(CompleteData,2)
        raw = cell([size(num,1)+1 size(num,2)]);
        raw(1,:) = txt;
        raw(2:end,:) = num2cell(num);
    end
end
% check for entire column with NaN
try
    CompleteData(:,(sum(isnan(CompleteData.Variables))==size(CompleteData,1)))= []; % eliminate all columns with entire NaN rows
end
try
    a = sum(cell2mat(cellfun(@sum,cellfun(@isnan,cellfun(@double,raw,'UniformOutput',false),'UniformOutput',false),'UniformOutput',false)),1);
    if size(a,2)>1
        raw(:,a>(size(raw,1)/.9)) = []; % if 90 percent of a row is nan it will eliminate
    end
    raw(find((cellfun(@(x) strcmp(x,'ActiveX VT_ERROR: '),raw)))) = {NaN};
end
inputDataHeder = CompleteData.Properties.VariableNames(1,:);

% -- check the header
% check if first row number mistakenly suppose as a header
isNumberHeader = true(1,size(raw,2));
if size(raw,1)~=size(CompleteData,1) || sum((cell2mat(cellfun(@(x) isnan(x),raw(1,:),'UniformOutput',false))))>0
    for i=1:size(raw,2)
        if isnumeric(raw{1,1}) && ~sum((cell2mat(cellfun(@(x) isnan(x),raw(1,i),'UniformOutput',false))))>0 %
            isNumberHeader(i) = true;
        elseif isstring(raw{1,i}) || ischar(raw{1,i}) || sum((cell2mat(cellfun(@(x) isnan(x),raw(1,i),'UniformOutput',false))))>0 % if some of header missed
            if  ~isnan(str2double(raw{1,i}))
                isNumberHeader(i) = true;
            elseif sum((cell2mat(cellfun(@(x) isnan(x),raw(1,i),'UniformOutput',false))))>0 % if some of header missed
                isNumberHeader(i) = false;
            else
                isNumberHeader(i) = false;
            end
        end
    end
end
if sum(isNumberHeader) == size(raw,2) % every first row are numeric
    CompleteData   = raw;
    % define headers
    varNum = 1:size(raw,2);
    for i =1:numel(varNum)
        headerName{i}= char(['Var' num2str(varNum(i))]);
    end
    if exist('headerName','var')
        inputDataHeder = headerName;
    end
else
    % if fisrt row is chars
    isTxtHeader = false(1,size(raw,2));
    for i=1:size(raw,2)
        if isstring(raw{1,i}) || ischar(raw{1,i})
            try
                if sum(cell2mat(strfind(raw(2:end,1),raw(1,1)))) == 0
                    isTxtHeader(i) = true;
                else
                    isTxtHeader(i) = false;
                end
            catch ME
                if strcmpi(ME.message,'Cell must be a cell array of character vectors.')
                    isTxtHeader(i) = true;
                end
            end
        end
    end
    if sum(isTxtHeader) == size(raw,2)
        CompleteData   = raw(2:end,:);
        inputDataHeder = raw(1,:);
    elseif sum((cell2mat(cellfun(@(x) isnan(x(~isTxtHeader)),raw(1,:),'UniformOutput',false))))>0 % if some of header missed
        nanIndex = logical((cell2mat(cellfun(@(x) isnan(x(~isTxtHeader)),raw(1,:),'UniformOutput',false))));
        CompleteData = raw;
        % define headers
        for i =1:sum(nanIndex)
            headerName{i}= char(['Var' num2str((i))]);
        end
        inputDataHeder = raw(1,:);
        inputDataHeder(nanIndex)=headerName;
    else
        CompleteData = raw;
        % define headers
        varNum = 1:size(raw,2);
        for i =1:numel(varNum)
            headerName{i}= char(['Var' num2str(varNum(i))]);
        end
        inputDataHeder = headerName;
    end
end
% -- check the content of the excel

% check if data combine with the Catogorized, Label, Char,
% and string data

[inputdata, Time] = numberizeLabelData(CompleteData);
if ~isempty(Time.dateTime)
    inputDataHeder = inputDataHeder(~Time.TimeIndex);
end
%%-- check the Missing values in the loaded file
k=5;
if sum(sum(isnan(inputdata)))>0
    Time.TimeIndex(:,(sum(isnan(inputdata))==size(inputdata,1))) = []; % eliminate all columns with entire NaN rows
    CompleteData(:  ,(sum(isnan(inputdata))==size(inputdata,1))) = []; % eliminate all columns with entire NaN rows
    inputDataHeder(:,(sum(isnan(inputdata))==size(inputdata,1))) = []; % eliminate all columns with entire NaN rows
    inputdata(:     ,(sum(isnan(inputdata))==size(inputdata,1))) = []; % eliminate all columns with entire NaN rows
    if sum(sum(isnan(inputdata))) == 0
        return;
    end
    sumation = sum(isnan(inputdata));
    NumMissInclmn = num2str(sumation(sumation>0));
    MissInclmn    = inputDataHeder(sumation>0);
    inputdata = DataImputation(app,inputdata,inputDataHeder,k);
    disp('input data contain some missing values')
end
Time.TimeIndex = find(Time.TimeIndex);

if strcmpi(opt.dataPreprocessMode,'Data Normalization')
    normData = DataNormalization(inputdata);
elseif strcmpi(opt.dataPreprocessMode,'Data Standardization')
    normData = DataStandardization(inputdata);
elseif strcmpi(opt.dataPreprocessMode,'None')
    normData = inputdata;
end

if strcmpi(mode,'input')
    data.inputDataFileName = chosenfile;
    data.inputCompleteData = CompleteData;
    data.inputDataHeder    = inputDataHeder;
    data.inputData         = inputdata;
    data.inputTime         = Time;
    data.inputNormData     = normData;
    data.isInputDataRead   = true;
elseif strcmpi(mode,'target')
    data.targetDataFileName = chosenfile;
    data.targetCompleteData = CompleteData;
    data.targetDataHeder    = inputDataHeder;
    data.targetData         = inputdata;
    data.targetTime         = Time;
    data.targetNormData     = normData;
    data.isTargetDataRead   = true;
end
end

%% ----- Local Functions -------
function vars = DataNormalization(data)
for i=1:size(data,2)
    vars(:,i) = (data(:,i) -min(data(:,i)))./ (max(data(:,i))-min(data(:,i)));
end
end

function  vars = DataStandardization(data)
for i=1:size(data,2)
    x.mu(1,i)   = mean(data(:,i),'omitnan');
    x.sig(1,i)  = std (data(:,i),'omitnan');
    vars(:,i) = (data(:,i) - x.mu(1,i))./ x.sig(1,i);
end
end
    
        

function [isTime, DateTime] = isDateTime(Data)
% check first row of data
if ~sum(isnan(Data{1,1}))>0
    a = Data{1,1};
elseif ~sum(isnan(Data{2,1}))>0
    a = Data{2,1};
else
    isTime = false;
    DateTime = [];
end
dateTime = Data;
% prune data time from Greenwich acronym(GMT, ...)
TempStr = {'GMT','LMT','ZULU', '+'};
t = a;
isFindZone =false;
for ZoneInd = TempStr
    if contains(a,ZoneInd)
        t = extractBefore(a,ZoneInd);
        isFindZone = true;
        break;
    end
end
t = strip(t);

%  --  build most frequently model
Year = {'yyyy-MM-dd' 'dd/MM/yyyy' 'dd.MM.yyyy'};
Hour = {'HH:mm:ss.SSS' 'HH:mm:ss.SSS Z' 'HH:mm:ss' 'T HH:mmXXX' 'HH:mm:ss Z'};
YearPerms = perms(Year);
clear tmp;
ind = 1;
for TempStrInd =1:size(Year,2)
    for j =1:size(Hour,2)
        tmp{ind,1} = ...
            [Year{TempStrInd} ' ' Hour{j}];
        ind = ind+1;
    end
end
Date = tmp;

% possible dates
Date{end+1} = 'MMMM d, yyyy HH:mm:ss Z';
Date{end+1} = 'MMMM d, yyyy';
Date{end+1} = 'MM/dd/yyyy';
Date{end+1} = 'MM.dd.yyyy';


isTime = false;
for i =1:numel(Date)
    try
        datetime(t,'InputFormat',Date{i,1});
        dateFormat = Date{i};
    end
end

% extract date time for all af rows
NaNdateTimeIndex = (cellfun(@isnan,Data,'UniformOutput',false)); % check if it contains missing values
NaNdateTimeIndex =  logical(cell2mat(cellfun(@(x) length(x)==1&& x==1,NaNdateTimeIndex,'UniformOutput',false)));
if isFindZone
    Time(~NaNdateTimeIndex,1) = extractBefore(Data(~NaNdateTimeIndex),ZoneInd);
else
    Time(~NaNdateTimeIndex,1) = Data(~NaNdateTimeIndex);
end
try
    DateTime(~NaNdateTimeIndex,1) = datetime(Time(~NaNdateTimeIndex),'InputFormat',dateFormat);
    isTime = true;
end

if sum(NaNdateTimeIndex)>0
    DateTime = fillmissing(DateTime,'linear');
    str = {'Input file contains date time with missing values.' 'They fill linearly.'};
    uiconfirm(app.mainWindow,str,'Date Missing Value',...
        'Options',{'OK'},...
        'DefaultOption',1,'CancelOption',1,'Icon','info');
end
if ~exist('DateTime',"var")
    DateTime = Data;
end

end


function imputData = DataImputation(app,missData,inputDataHeder,k)
Str = ([{'Input file contains some Missing Values.'} {'they atumatically replaced by K-NN Minkowski algorithm.'}]);
%             uialert(app.mainWindow,Str,'Missing data','Icon','Warning');

uiconfirm(app.mainWindow,Str,'Missing Value',...
    'Options',{'OK'},...
    'DefaultOption',1,'CancelOption',1,'Icon','info');
figure(app.mainWindow);
%  finding the missing value Column type (continues or discrete)
NaNCount = (sum(isnan(missData)));
figure('Name','Misisng Data Distribution',...
    'Toolbar','none',...
    'MenuBar', 'none',...
    'NumberTitle','off');

for i=1:size(NaNCount,2)
    text((i),NaNCount(i),num2str(NaNCount(i)),...
        'HorizontalAlignment','center',...
        'VerticalAlignment','bottom');
end
xlabel('')
[NaNCount,indx] = sort(NaNCount);
Title = 'Missing Values Distribution';
bar(NaNCount); title(Title); ylabel('Count of Missing Values'); xlabel('Predictors');
ax = gca;

ax.XTickLabel = inputDataHeder(indx); grid on;
if length(inputDataHeder)<4
    ax.XTickLabelRotation = 0;
else
    ax.XTickLabelRotation = 45;
end

for i=1:size(NaNCount,2)
    text((i),NaNCount(i),num2str(NaNCount(i)),...
        'HorizontalAlignment','center',...
        'VerticalAlignment','bottom');
end
set(gca,'xtick',1:(numel(inputDataHeder(1:end))));
xlabel('');

% missing value index
missIndx = ismissing(missData);
discreteIndx = false(1,size(missData,2));
for i=1:size(missData,2)
    discreteIndx(i) = isClassificationData(app,missData(:,i));
end
imputData = [];
try
    imputData = knnimpute(missData,k,'Distance','minkowski','DistArgs',5);
catch ME
    uialert(app.mainWindow,[ME.message 'Eliminate that rows and reload the data.'],'Missing data','Icon','Error');
    return;
end
imputData(:,discreteIndx) = round(imputData(:,discreteIndx));

% check for any miss value on the edge of the data and
% replac thier mean
missIndx = ismissing(imputData);
if sum(sum(missIndx))>0
    imputData = fillmissing(imputData,'linear');
end
end

function [deLabelData, Time]  = numberizeLabelData(data)
if istable(data)
    data = table2cell(data);
end
Time.dateTime = [];
newData = zeros(size(data));
LabelIndex = isLabelData(data);
% check for date time column between label columns
timeIndx = 1:length(LabelIndex);
timeIndx = timeIndx(LabelIndex);
isTime = false;
Time.TimeIndex = false([1 size(data,2)]);
if ~isempty(timeIndx)
    for i = timeIndx
        [isTime, Time.dateTime] = isDateTime(data(:,i));
        if isTime
            Time.TimeIndex(i) = true;
            LabelIndex(i) = false;
            break;
        end
    end
end

indx = 1:size(data,2);
for i=indx(LabelIndex)
    [uniqueMem,ia,ic] = unique(data(:,i),'stable');
    for j =1:size(data,1)
        for k =1:numel(uniqueMem)
            if strcmp(data(j,i),uniqueMem(k))
                temp(j,1)= (k);
            end
        end
    end
    newData(:,indx(i)) = temp;
end
try
    newData(:,indx(~LabelIndex & ~Time.TimeIndex)) = cell2mat(data(:,indx(~LabelIndex & ~Time.TimeIndex)));
catch ME
    if strcmpi(ME.identifier,'MATLAB:cell2mat:MixedDataTypes') || strcmpi(ME.identifier,'MATLAB:subsassigndimmismatch')
        for i = indx(~LabelIndex & ~Time.TimeIndex)
            for j=1:size(data,1)
                if isnumeric(data{j,i})
                    newData(j,i) = data{j,i};
                elseif ischar(data{j,i}) || isstring(data{j,i})
                    newData(j,i) = str2double(data{j,i});
                end
            end
        end
    else
        disp('Unknown Error in loading input file. please check your file is not corrupted.');
    end
end
deLabelData = newData;
deLabelData = deLabelData(:,~Time.TimeIndex);
end

function t = isLabelData(data) % check if there are some label column
t = false(1,size(data,2));
if istable(data)
    data = table2cell(data);
end
if iscell(data)
    for i=1:size(data,2)
        if (ischar((cell2mat(data(1,i)))) || isstring((cell2mat(data(1,i)))) || isnan((cell2mat(data(1,i)))) ) && ...
                ( ischar((cell2mat(data(2,i)))) || isstring((cell2mat(data(2,i)))) ) && ...
                ( ischar((cell2mat(data(end,i)))) || isstring((cell2mat(data(end,i)))) ) && ...
                ( isnan(str2double(cell2mat(data(1,i)))) && isnan(str2double(cell2mat(data(end,i)))) )
            t(i) = true;
        else
            t(i) = false;
        end
    end
end
end