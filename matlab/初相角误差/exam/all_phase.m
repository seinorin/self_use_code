%���������ݴ�����Ϊ1��excel�ļ��У������нǶȷ����ź�������
clc;close all;clear;

R= xlsread('01.csv');
[N,M]=size(R);%NΪ����,MΪ����
A=zeros(1,M);
B=zeros(1,M);
for i=1:M
    Z=fft(R,N);%FFT�任
    %Am=abs(Z)*2/N;%��ģ(��������)
    %A(1,i)=(Z(1))/N;%ֱ������
    ph=angle(Z);%������
    P(i) = ph(2,i);%�в�����λ;
end
%��е�����num/3600/pole
PHASE=P';%��Ŵ�ʱ�ĳ���λֵ�����ڱȽ�




