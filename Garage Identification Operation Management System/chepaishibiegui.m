function varargout = chepaishibiegui(varargin)
% CHEPAISHIBIEGUI MATLAB code for chepaishibiegui.fig
%      CHEPAISHIBIEGUI, by itself, creates a new CHEPAISHIBIEGUI or raises the existing
%      singleton*.
%
%      H = CHEPAISHIBIEGUI returns the handle to a new CHEPAISHIBIEGUI or the handle to
%      the existing singleton*.
%
%      CHEPAISHIBIEGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CHEPAISHIBIEGUI.M with the given input arguments.
%
%      CHEPAISHIBIEGUI('Property','Value',...) creates a new CHEPAISHIBIEGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before chepaishibiegui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to chepaishibiegui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help chepaishibiegui


% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @chepaishibiegui_OpeningFcn, ...
    'gui_OutputFcn',  @chepaishibiegui_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before chepaishibiegui is made visible.
function chepaishibiegui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to chepaishibiegui (see VARARGIN)

% Choose default command line output for chepaishibiegui
handles.output = hObject;
handles.option=[];

% Update handles structure
guidata(hObject, handles); 

% UIWAIT makes chepaishibiegui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = chepaishibiegui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output; 


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[fname,pname,index] = uigetfile({'*.jpg';'*.bmp'},'选择图片');
if index
    str = [pname fname];
    c = imread(str);
    axes(handles.chepai);
    imshow(c);
    I = c;
    title('汽车入库采集');
    imwrite(I,'原图.jpg');
    I1=rgb2gray(I);%灰度处理
    imwrite(I1,'灰度图.jpg');
    
    I2=edge(I1,'roberts',0.18,'both');%边缘检测
    imwrite(I2,'边缘检测图.jpg');
    
    
    se=[1;1;1];
    I3=imerode(I2,se);%腐蚀，把细线进一步细化
    imwrite(I3,'腐蚀图.jpg');
    se=strel('rectangle',[25,25]);
    I4=imclose(I3,se);%闭运算，连同虚线区域成线，并且填充连线区域
    imwrite(I4,'闭运算图.jpg');
    [n1, n2] = size(I4);
    I4(1:round(n1/3), 1:n2) = 0;
    
    r = floor(n1/10);
    c = floor(n2/10);
    I4(1:r,:)=0;
    I4((9*r):n1,:)=0;
    I4(:,1:c)=0;
    I4(:,(c*9):n2)=0;
    I5=bwareaopen(I4,200);  %去除小面积，面积小于200的为干扰
    imwrite(I5,'去除小面积.jpg');
    [y,x,z]=size(I5);
    myI = double(I5);
    tic
    Blue_y=zeros(y,1);
    for i=1:y   %根据车牌二值图进行投影定位，以分割车牌
        for j=1:x
            if(myI(i,j,1)==1)
                Blue_y(i,1)=Blue_y(i,1)+1;
            end
        end
    end
    [temp MaxY] = max(Blue_y);
    
    PY1=MaxY;
    while((Blue_y(PY1,1)>=5)&&(PY1>1))
        PY1=PY1-1;
    end
    PY2=MaxY;
    while ((Blue_y(PY2,1)>=5)&&(PY2<y))
        PY2=PY2+1;
    end
    IY=I(PY1:PY2,:,:);
    % figure,imshow(IY);
    imwrite(IY,'行投影.jpg');
    Blue_x=zeros(1,x);
    for j=1:x
        for i=PY1:PY2
            if(myI(i,j,1)==1)
                Blue_x(1,j)=Blue_x(1,j)+1;
            end
        end
    end
    % [tempx MaxX] = max(Blue_x);
    PX1=1;
    [Irow,Icol,Idisanwei] = size(I);
    while((Blue_x(1,PX1)<3)&&(PX1<x))
        PX1=PX1+1;
    end
    PX2=x;
    while ((Blue_x(1,PX2)<3)&&(PX2>PX1))
        PX2=PX2-1;
    end
    PX1=PX1-1;
    PX2=PX2;
    % dw=I(PY1:(PY2-8),PX1:PX2,:);
    dw=I((PY1):(PY2),PX1:PX2,:); %裁剪车牌
    t=toc;
    
    if ((PX2-PX1)/(PY2-PY1))>4.6
        PX1=1;
        [Irow,Icol,Idisanwei] = size(I);
        while((Blue_x(1,PX1)<11)&&(PX1<x))
            PX1=PX1+1;
        end
        PX2=x;
        while ((Blue_x(1,PX2)<11)&&(PX2>PX1))
            PX2=PX2-1;
        end
        PX1=PX1-1;
        PX2=PX2;
        dw=I((PY1):(PY2),PX1:PX2,:);
    end
    imwrite(dw,'定位到的车牌图.jpg');
    a=imread('定位到的车牌图.jpg');
    axes(handles.chepaijieguo);
    imshow(a);
    title('车牌分割结果')
    b=rgb2gray(a);
    imwrite(b,'车牌灰度图.jpg');
    
    g_max=double(max(max(b)));
    g_min=double(min(min(b)));
    T=round(g_max-(g_max-g_min)/3);
    [m,n]=size(b);
    d=(double(b)>=T);
    imwrite(d,'车牌二值图.jpg');
    
    
    h=fspecial('average',3);
    
    d=im2bw(round(filter2(h,d)));
    imwrite(d,'滤波后的车牌图.jpg');
    
    
    
    se=eye(2);
    [m,n]=size(d);
    if bwarea(d)/m/n>=0.365
        d=imerode(d,se);
    elseif bwarea(d)/m/n<=0.235
        d=imdilate(d,se);
    end
    imwrite(d,'形态学.jpg');
    
    [dw1,dw2,dw3]=size(dw);
    fanwei = round(0.0026*dw1*dw2);
    d=bwareaopen(d,fanwei);
    d=qiege(d);%%字符切割，根据连通域的方法
    [m,n]=size(d);
    if (n/m)<4
        row = m-(n/(4.1));
        d = d(round(row):m,1:n);
    end
    
    k1=1;
    k2=1;
    s=sum(d);
    j=1;
    while j~=n
        while s(j)==0
            j=j+1;
        end
        k1=j;
        while s(j)~=0&&j<=n-1
            j=j+1;
        end
        k2=j-1;%
        if k2-k1>=round(n/6.5)%
            [val,num]=min(sum(d(:,[k1+5:k2-5])));%
            d(:,k1+num+5)=0;  %
        end
    end
    
    % 再切割
    d=qiege(d);
    
    
    y1=10;y2=0.25;flag=0;word1=[];
    while flag==0
        [m,n]=size(d);
        left=1;wide=0;
        while sum(d(:,wide+1))~=0
            wide=wide+1;
        end
        
        if (wide<5)&&(sum(d(:,wide+1))<(10/m))
            d(:,[1:wide])=0;
            d=qiege(d);
        else
            temp=qiege(imcrop(d,[1 1 wide m]));
            [m,n]=size(temp);
            all=sum(sum(temp));
            two_thirds=sum(sum(temp([round(m/3):2*round(m/3)],:)));
            if two_thirds/all>y2
                flag=1;word1=temp;   % WORD 1
            end
            d(:,[1:wide])=0;d=qiege(d);
        end
    end
    [word2,d]=getword(d);
    [word2row,word2col] = size(word2);
    whitesizeofword2 = round(word2row*word2col/12)+1;
    word2=bwareaopen(word2,whitesizeofword2);
    word2=qiege(word2);
    % 分割出第三个字符
    [word3,d]=getword(d);
    % 分割出第四个字符
    [word4,d]=getword(d);
    % 分割出第五个字符
    [word5,d]=getword(d);
    % 分割出第六个字符
    [word6,d]=getword(d);
    [word6row,word6col] = size(word6);
    whitesizeofword6 = round(word6row*word6col/12)+1;
    word6=bwareaopen(word6,whitesizeofword6);
    word6=qiege(word6);
    % 分割出第七个字符
    [word7,d]=getword(d);
    
    [m,n]=size(word1);
    
    word1=imresize(word1,[32 16]);
    
    word2=wordprocess(word2);
    word3=wordprocess(word3);
    word4=wordprocess(word4);
    word5=wordprocess(word5);
    word6=wordprocess(word6);
    word7=wordprocess(word7);
    axes(handles.zifu1);
    imshow(word1);
    title('1')
    axes(handles.zifu2);
    imshow(word2);
    title('2')
    axes(handles.zifu3);
    imshow(word3);
    title('3')
    axes(handles.zifu4);
    imshow(word4);
    title('4')
    axes(handles.zifu5);
    imshow(word5);
    title('5')
    axes(handles.zifu6);
    imshow(word6);
    title('6')
    axes(handles.zifu7);
    imshow(word7);
    title('7')
    
    imwrite(word1,'1.jpg');
    imwrite(word2,'2.jpg');
    imwrite(word3,'3.jpg');
    imwrite(word4,'4.jpg');
    imwrite(word5,'5.jpg');
    imwrite(word6,'6.jpg');
    imwrite(word7,'7.jpg');
    
    %全字符模板库,模板匹配方法
    tic
    char=[];
    store=strcat('A','B','C','D','E','F','G','H','J','K','L','M','M',......
        'N','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5',......
        '6','7','8','9','京','津','沪','渝','冀','晋','辽','吉','黑','苏','浙' ,'皖','闽','赣',......
        '鲁','豫','鄂','湘','粤','琼','川','贵','云','陕','甘','青','藏','桂','蒙','新','宁','港');
    %模板匹配方法
    for i=1:7
        for j=1:67
            Im=eval(strcat('word',num2str(i)));
            Template=imread(strcat('example\',num2str(j),'.bmp'));
            Template=im2bw(Template);
            Differ=Im-Template;
            Compare(j)=sum(sum(abs(Differ)));
        end
        index=find(Compare==(min(Compare)));
        char=[char store(index)];
    end
    set(handles.text20,'string',char);
    pause(4)
    %%语音播报
    duchushengyin(char);
    time2=toc;
    %set(handles.edit2,'string',time2)
    %识别时间
    set(handles.text21,'string',datestr(now))
    fid=fopen('Data_in.txt','a+');
    fprintf(fid,'%s\r\n',char,datestr(now));
    fclose(fid);
end
num=handles.num;
num=num-1;
handles.num=num;
set(handles.text37,'string',num);
b=handles.a;
a=handles.a;
a=a-1;
handles.a=a;
set(handles.text41,'string',a);
set(handles.text49,'string',b);
set(handles.text50,'string',b);
set(handles.text51,'string',b);
guidata(hObject, handles);






function wenzijieguo_Callback(hObject, eventdata, handles)
% hObject    handle to wenzijieguo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wenzijieguo as text
%        str2double(get(hObject,'String')) returns contents of wenzijieguo as a double


% --- Executes during object creation, after setting all properties.
function wenzijieguo_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wenzijieguo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
clc
close all
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in radiobutton1.
function radiobutton1_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton1


% --- Executes on button press in radiobutton2.
function radiobutton2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2



function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
[fname,pname,index] = uigetfile({'*.jpg';'*.bmp'},'选择图片');
if index
    str = [pname fname];
    c = imread(str);
    axes(handles.axes10);
    imshow(c);
    I = c;
    title('汽车出库采集');
    I1=rgb2gray(I);
    I2=edge(I1,'roberts',0.18,'both');
    se=[1;1;1];
    I3=imerode(I2,se);
    se=strel('rectangle',[25,25]);
    I4=imclose(I3,se);
    [n1, n2] = size(I4);
    I4(1:round(n1/3), 1:n2) = 0;
    
    r = floor(n1/10);
    c = floor(n2/10);
    I4(1:r,:)=0;
    I4((9*r):n1,:)=0;
    I4(:,1:c)=0;
    I4(:,(c*9):n2)=0;
    I5=bwareaopen(I4,200);
    [y,x,z]=size(I5);
    myI = double(I5);
    tic
    Blue_y=zeros(y,1);
    for i=1:y
        for j=1:x
            if(myI(i,j,1)==1)
                Blue_y(i,1)=Blue_y(i,1)+1;
            end
        end
    end
    [temp MaxY] = max(Blue_y);
    
    PY1=MaxY;
    while((Blue_y(PY1,1)>=5)&&(PY1>1))
        PY1=PY1-1;
    end
    PY2=MaxY;
    while ((Blue_y(PY2,1)>=5)&&(PY2<y))
        PY2=PY2+1;
    end
    IY=I(PY1:PY2,:,:);
    % figure,imshow(IY);
    
    Blue_x=zeros(1,x);
    for j=1:x
        for i=PY1:PY2
            if(myI(i,j,1)==1)
                Blue_x(1,j)=Blue_x(1,j)+1;
            end
        end
    end
    % [tempx MaxX] = max(Blue_x);
    PX1=1;
    [Irow,Icol,Idisanwei] = size(I);
    while((Blue_x(1,PX1)<3)&&(PX1<x))
        PX1=PX1+1;
    end
    PX2=x;
    while ((Blue_x(1,PX2)<3)&&(PX2>PX1))
        PX2=PX2-1;
    end
    PX1=PX1-1;
    PX2=PX2;
    % dw=I(PY1:(PY2-8),PX1:PX2,:);
    dw=I((PY1):(PY2),PX1:PX2,:);
    t=toc;
    
    if ((PX2-PX1)/(PY2-PY1))>4.6
        PX1=1;
        [Irow,Icol,Idisanwei] = size(I);
        while((Blue_x(1,PX1)<11)&&(PX1<x))
            PX1=PX1+1;
        end
        PX2=x;
        while ((Blue_x(1,PX2)<11)&&(PX2>PX1))
            PX2=PX2-1;
        end
        PX1=PX1-1;
        PX2=PX2;
        dw=I((PY1):(PY2),PX1:PX2,:);
    end
    
    
    
    
    imwrite(dw,'车牌分割图.jpg');
    a=imread('车牌分割图.jpg');
    axes(handles.axes18)
    imshow(a)
    title('车牌分割结果')
    b=rgb2gray(a);
    imwrite(b,'车牌灰度图.jpg');
    
    g_max=double(max(max(b)));
    g_min=double(min(min(b)));
    T=round(g_max-(g_max-g_min)/3);
    [m,n]=size(b);
    d=(double(b)>=T);
    imwrite(d,'车牌二值图.jpg');
    
    
    h=fspecial('average',3);
    
    d=im2bw(round(filter2(h,d)));
    imwrite(d,'滤波后的图.jpg');
    
    
    
    se=eye(2);
    [m,n]=size(d);
    if bwarea(d)/m/n>=0.365
        d=imerode(d,se);
    elseif bwarea(d)/m/n<=0.235
        d=imdilate(d,se);
    end
    imwrite(d,'腐蚀或者膨胀的车牌图.jpg');
    
    
    
    [dw1,dw2,dw3]=size(dw);
    fanwei = round(0.0026*dw1*dw2);
    d=bwareaopen(d,fanwei);
    d=qiege(d);
    [m,n]=size(d);
    if (n/m)<4
        row = m-(n/(4.1));
        d = d(round(row):m,1:n);
    end
    
    k1=1;
    k2=1;
    s=sum(d);
    j=1;
    while j~=n
        while s(j)==0
            j=j+1;
        end
        k1=j;
        while s(j)~=0&&j<=n-1
            j=j+1;
        end
        k2=j-1;%
        if k2-k1>=round(n/6.5)%
            [val,num]=min(sum(d(:,[k1+5:k2-5])));%
            d(:,k1+num+5)=0;  %
        end
    end
    
    % 再切割
    d=qiege(d);
    
    
    y1=10;y2=0.25;flag=0;word1=[];
    while flag==0
        [m,n]=size(d);
        left=1;wide=0;
        while sum(d(:,wide+1))~=0
            wide=wide+1;
        end
        
        if (wide<5)&&(sum(d(:,wide+1))<(10/m))
            d(:,[1:wide])=0;
            d=qiege(d);
        else
            temp=qiege(imcrop(d,[1 1 wide m]));
            [m,n]=size(temp);
            all=sum(sum(temp));
            two_thirds=sum(sum(temp([round(m/3):2*round(m/3)],:)));
            if two_thirds/all>y2
                flag=1;word1=temp;   % WORD 1
            end
            d(:,[1:wide])=0;d=qiege(d);
        end
    end
    [word2,d]=getword(d);
    [word2row,word2col] = size(word2);
    whitesizeofword2 = round(word2row*word2col/12)+1;
    word2=bwareaopen(word2,whitesizeofword2);
    word2=qiege(word2);
    % 分割出第三个字符
    [word3,d]=getword(d);
    % 分割出第四个字符
    [word4,d]=getword(d);
    % 分割出第五个字符
    [word5,d]=getword(d);
    % 分割出第六个字符
    [word6,d]=getword(d);
    [word6row,word6col] = size(word6);
    whitesizeofword6 = round(word6row*word6col/12)+1;
    word6=bwareaopen(word6,whitesizeofword6);
    word6=qiege(word6);
    % 分割出第七个字符
    [word7,d]=getword(d);
    
    [m,n]=size(word1);
    
    word1=imresize(word1,[32 16]);
    
    word2=wordprocess(word2);
    word3=wordprocess(word3);
    word4=wordprocess(word4);
    word5=wordprocess(word5);
    word6=wordprocess(word6);
    word7=wordprocess(word7);
    axes(handles.axes11);
    imshow(word1);
    title('1')
    axes(handles.axes12);
    imshow(word2);
    title('2')
    axes(handles.axes13);
    imshow(word3);
    title('3')
    axes(handles.axes14);
    imshow(word4);
    title('4')
    axes(handles.axes15);
    imshow(word5);
    title('5')
    axes(handles.axes16);
    imshow(word6);
    title('6')
    axes(handles.axes17);
    imshow(word7);
    title('7')
    
    imwrite(word1,'1.jpg');
    imwrite(word2,'2.jpg');
    imwrite(word3,'3.jpg');
    imwrite(word4,'4.jpg');
    imwrite(word5,'5.jpg');
    imwrite(word6,'6.jpg');
    imwrite(word7,'7.jpg');
    %识别算法
    
    %全字符模板库,模板匹配方法
    tic
    char=[];
    store=strcat('A','B','C','D','E','F','G','H','J','K','L','M','M',......
        'N','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5',......
        '6','7','8','9','京','津','沪','渝','冀','晋','辽','吉','黑','苏','浙' ,'皖','闽','赣',......
        '鲁','豫','鄂','湘','粤','琼','川','贵','云','陕','甘','青','藏','桂','蒙','新','宁','港');
    for i=1:7
        for j=1:67
            Im=eval(strcat('word',num2str(i)));
            Template=imread(strcat('example\',num2str(j),'.bmp'));
            Template=im2bw(Template);
            Differ=Im-Template;
            Compare(j)=sum(sum(abs(Differ)));
        end
        index=find(Compare==(min(Compare)));
        char=[char store(index)];
    end
    set(handles.text23,'string',char);
    
    time2=toc;
    %计费
    %计时
    set(handles.text24,'string',datestr(now));
    pause(2)
    duchushengyin(char);
    fid=fopen('Data_out.txt','a+');
    fprintf(fid,'%s\r\n',char,datestr(now));
    fclose(fid);
    %计费
    %与文本文件数据对比
    file=fopen('Data_in.txt');
    while feof(file)~=1
        fid=fgetl(file);
        %% if(strcmp(fid,char)==1)
        fic=fgetl(file);
        %%end
    end
    fclose(file);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    file1=fopen('Data_out.txt');
    while feof(file1)~=1
        fid1=fgetl(file1);%从文件中一次读取一行，一直到文件的末尾。此时fid1=chu库数据
        %% if(strcmp(fid,char)==1)
    end
        %%end
    fclose(file1);%关闭文件
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    
    fie=datevec(fic);%datevec将入库日期和时间转换为分量向量，其六个元素表示 t 的年、月、日、小时、分钟和秒分量。
    fid11=datevec(fid1);%datevec将出库日期和时间转换为分量向量，其六个元素表示 t 的年、月、日、小时、分钟和秒分量。
    ts=etime(fid11,fie)-22;%计算日期向量之间流逝的时间
    %%%%计费
    price=handles.price;
    price=price/3600  ; %转为每秒费用
    set(handles.text16,'string',ts);
    RMB=price*ts;
    %四舍五入，保留2位小数
    RMB=roundn(RMB,-2);
    set(handles.text18,'string',RMB);
end
num=handles.num;
num=num+1;
set(handles.text37,'string',num)
handles.num=num;
a=handles.a;
a=a+1;
set(handles.text41,'string',a)
handles.a=a;
guidata(hObject, handles);




% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit9_Callback(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit9 as text
%        str2double(get(hObject,'String')) returns contents of edit9 as a double


% --- Executes during object creation, after setting all properties.
function edit9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
num=str2num(get(handles.edit9,'String'));
handles.num=num;
a=str2num(get(handles.edit9,'String'));
a=a/4;
handles.a=a;
guidata(hObject, handles);
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit10_Callback(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit10 as text
%        str2double(get(hObject,'String')) returns contents of edit10 as a double


% --- Executes during object creation, after setting all properties.
function edit10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
price=str2num(get(handles.edit10,'String'));
handles.price=price;
guidata(hObject, handles);
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in radiobutton3.
function radiobutton3_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',1);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('灰度图.jpg');
title('灰度图');
% hObject    handle to radiobutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton3


% --- Executes on button press in radiobutton4.
function radiobutton4_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',1);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('边缘检测图.jpg');
title('边缘检测图');
% hObject    handle to radiobutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton4


% --- Executes on button press in radiobutton5.
function radiobutton5_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',1);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('腐蚀图.jpg');
title('腐蚀图');
% hObject    handle to radiobutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton5


% --- Executes on button press in radiobutton6.
function radiobutton6_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',1);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('原图.jpg');
title('原图');
% hObject    handle to radiobutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton6


% --- Executes on button press in radiobutton7.
function radiobutton7_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',1);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('闭运算图.jpg');
title('闭运算图');
% hObject    handle to radiobutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton7


% --- Executes on button press in radiobutton8.
function radiobutton8_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',1);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('去除小面积.jpg');
title('去除小面积');
% hObject    handle to radiobutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton8


% --- Executes on button press in radiobutton9.
function radiobutton9_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',1);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('行投影.jpg');
title('行投影');
% hObject    handle to radiobutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton9


% --- Executes on button press in radiobutton10.
function radiobutton10_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',1);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('定位到的车牌图.jpg');
title('定位');
% hObject    handle to radiobutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton10


% --- Executes on button press in radiobutton11.
function radiobutton11_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',1);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('车牌灰度图.jpg');
title('车牌灰度化');
% hObject    handle to radiobutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton11


% --- Executes on button press in radiobutton12.
function radiobutton12_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',1);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',0);
figure
imshow('车牌二值图.jpg');
title('车牌二值图');
% hObject    handle to radiobutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton12


% --- Executes on button press in radiobutton13.
function radiobutton13_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',1);
set(handles.radiobutton14,'value',0);
figure
imshow('滤波后的车牌图.jpg');
title('滤波');
% hObject    handle to radiobutton13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton13


% --- Executes on button press in radiobutton14.
function radiobutton14_Callback(hObject, eventdata, handles)
set(handles.radiobutton6,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
set(handles.radiobutton7,'value',0);
set(handles.radiobutton8,'value',0);
set(handles.radiobutton9,'value',0);
set(handles.radiobutton10,'value',0);
set(handles.radiobutton11,'value',0);
set(handles.radiobutton12,'value',0);
set(handles.radiobutton13,'value',0);
set(handles.radiobutton14,'value',1);
figure
imshow('膨胀或腐蚀后的图.jpg');
title('膨胀或腐蚀后的图');
% hObject    handle to radiobutton14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton14


% --- Executes during object creation, after setting all properties.
function chepaijieguo_CreateFcn(hObject, eventdata, handles)
% hObject    handle to chepaijieguo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate chepaijieguo


% --- Executes during object creation, after setting all properties.
function text6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to text6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function text10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to text10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object deletion, before destroying properties.
function text20_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to text20 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function axes10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes10


% --- Executes during object creation, after setting all properties.
function zifu7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to zifu7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate zifu7


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function chepai_CreateFcn(hObject, eventdata, handles)
% hObject    handle to chepai (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate chepai


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function text32_CreateFcn(hObject, eventdata, handles)
% hObject    handle to text32 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over edit9.
function edit9_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over text38.
function text38_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to text38 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function text38_CreateFcn(hObject, eventdata, handles)
% hObject    handle to text38 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes during object creation, after setting all properties.
function pushbutton1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in radiobutton15.
function radiobutton15_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton15
fprintf('您正处于中心区域，以下区域车位存在空闲：\北区：当前方向直走，剩余车位：25\南区：往反方向行驶，剩余车位：24\西区：前方路口左拐，剩余车位：25\东区：前方路口右拐，剩余车位：25')



function edit12_Callback(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit12 as text
%        str2double(get(hObject,'String')) returns contents of edit12 as a double


% --- Executes during object creation, after setting all properties.
function edit12_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a=str2num(get(handles.edit12,'String'));
handles.a=a-1;
guidata(hObject, handles);
