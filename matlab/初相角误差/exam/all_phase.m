%将仿真数据存入名为1的excel文件中，对所有角度仿真信号求初相角
clc;close all;clear;

R= xlsread('01.csv');
[N,M]=size(R);%N为行数,M为列数
A=zeros(1,M);
B=zeros(1,M);
for i=1:M
    Z=fft(R,N);%FFT变换
    %Am=abs(Z)*2/N;%求模(交流分量)
    %A(1,i)=(Z(1))/N;%直流分量
    ph=angle(Z);%求初相角
    P(i) = ph(2,i);%行波初相位;
end
%机械角误差num/3600/pole
PHASE=P';%存放此时的初相位值，便于比较




