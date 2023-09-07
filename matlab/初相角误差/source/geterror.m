function [error,P1,xlabledata]=geterror(P,pole)

%获取机械角误差
i=0:360/40:360-360/40;
i=i';
k=P-i;
k=k-sum(k)/length(k);
error=k/pole;
xlabledata=i/pole;
%获取谐波频次
L = length(error);             % Length of signa
Y=fft(error);
P2 = abs(Y);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);