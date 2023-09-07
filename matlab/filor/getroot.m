function [rootnum,angular,spwm,danum]=getroot(t,freq,daf)
%UNTITLED6 此处显示有关此函数的摘要
%   此处显示详细说明
% rootnum=sawtooth(2*2*pi*t,1/2);
rootnum=sin(t*2*pi*2000);
% plot(t,rootnum)%原始图像数据，5ms内的标准正弦数据，采样频率为100M
% hold on


%三角
% freq=100;%hz/ms 建议值100 此时一个正弦周期为50个采样
angular = sawtooth(freq*2000*pi*t,1/2);
% grid on

%SPWM
spwm=(rootnum>angular);
% plot(t,spwm)
%模拟DA
danum=rootnum;
for i=1:1:length(t)
  if mod(t(i)*2000,(1/daf))<2*10^-4
      danum(i)=rootnum(i);
  else
      danum(i)=danum(i-1);
  end
end

end

