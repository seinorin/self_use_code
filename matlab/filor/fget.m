function  [f,P1]=fget(num,t)
%num为输入数据
%Fs为采样频率
%endnum调节最终图形的横坐标
%   获取频谱信息
%若要得到1hz的频谱精度需要1s的输入时间
T=t(2)-t(1);
Fs = 1/T;             % Sampling period       
L = length(num);             % Length of signa
Y=fft(num);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;
end

