clc,clear;
%测试，简单的算法能不能搞
%用来测试用的信号
t=0.1:0.1:360;
num=360-t;
t=[t t t t t num];
key=t;
num1=0;
num2=0;
pole=0;
for i=1:length(t)
    num1=t(i);
    pole=dealtest(num1,num2,pole);
    num2=num1;
    key(i)=pole*72+num2/5;
end
plot(key)