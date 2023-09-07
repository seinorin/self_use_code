clc,clear;


%正弦
Fs = 100000000;            % Sampling frequency                    
T = 1/Fs;             % Sampling period       
L = 500001;             % Length of signal
t = (0:L-1)*T;        % Time vector
rootnum=0.7*sin(2*pi*5000*t) + sin(2*pi*2000*t);
Y=fft(rootnum);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

f = Fs*(0:(L/2))/L;
plot(f,P1) 
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')