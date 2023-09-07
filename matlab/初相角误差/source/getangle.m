function PHASE=getangle(R)
[N,M]=size(R);%N为行数,M为列数
% A=zeros(1,M);
% B=zeros(1,M);

Z=fft(R,N);%FFT变换
%     Am=abs(Z)*2/N;%求模(交流分量)
%     A(1,i)=(Z(1))/N;%直流分量
ph=angle(Z);%求初相角
P = ph(2,:);%行波初相位;
% end
% 机械角误差num/3600/pole
% PHASE=P';%存放此时的初相位值，便于比较
PHASE=P'/pi*180;
PHASE=sort(PHASE(1:40));
PHASE=PHASE-PHASE(1);