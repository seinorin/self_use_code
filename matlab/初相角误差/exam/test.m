clc;close all;clear;
DATA= xlsread('01.csv');
for i=1:(max(DATA(:,1))/0.9+1)
    R(:,i)=DATA((i*41-40):i*41,3);
end
%R=R0(25:41,:);
i=0:0.3:12;
[N,M]=size(R);%N为行数,M为列数
A=zeros(1,M);
B=zeros(1,M);
% for i=1:M
    Z=fft(R,N);%FFT变换
%     Am=abs(Z)*2/N;%求模(交流分量)
%     A(1,i)=(Z(1))/N;%直流分量
    ph=angle(Z);%求初相角
    P = ph(2,:);%行波初相位;
% end
% 机械角误差num/3600/pole
PHASE=P';%存放此时的初相位值，便于比较
PHASE=P'/pi*180/30;
% 
% num=PHASE-key';
% PHASE=PHASE/pi*180;
% y = fft(R,101);
% z=angle(y);
% % z=z/pi*180;
% plot(z)