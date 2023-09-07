function [R,pole]=getdata(adress)
%获取数据，每条线采集41个数据

DATA= xlsread(adress);
for i=1:(max(DATA(:,1))/0.9+1)
    R(:,i)=DATA((i*41-40):i*41,3);
    
end
pole=-360/(DATA(1*41,1)-DATA(2*41,1))/40;