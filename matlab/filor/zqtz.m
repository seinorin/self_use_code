function [t,out]=zqtz(num,N,time)
%拓展信号长度，用于FFT
out=num';
key=max(time);
t=time'/key;
time=t;
for i=1:1:N-1
    out=[out num'];
    t=[t time+i];
end
t=t'*key;
out=out';
end

