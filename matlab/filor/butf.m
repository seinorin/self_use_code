function out= butf(spwm,t)
%滤波
%spwm为输入信号
%t为spwm对应的时间参数
%理想的butter worth
% fc = 2000;%截止频率
% fs =25000000/pi;%采样频率
% [b,a] = butter(3,fc/(fs/2));
% % freqz(b,a)
% y = filtfilt(b,a,double(spwm));
% yy = filter(b,a,spwm);
% plot(t,yy)
% 
% 
% %设计的butterworth
c1=283/1000000;c2=111/1000000;c3=16.1/1000000;
A=c1*c2*c3;B=2*c3*(c1+c2);C=c2+3*c3;
numerator = 1 ;
denominator = [A,B,C,1];
sys = tf(numerator,denominator);
out=lsim(sys,spwm,t);

end

