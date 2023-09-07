function [errorout,P1data]=getoutdata()
hz=[2 2 1 1 2 1 1 2 2 1 1 2];
 for i = 1:12
%取实验数据
fileName = [num2str(i) '.csv'];
[R,pole]=getdata(fileName);
%获取初相角
P=getangle(R);
%获取机械角误差,谐波与其横坐标值
[mecerror,harmonic,xlabledata]=geterror(P,pole);
%处理误差、谐波，转化为可通用标准。
errorout(i)=sum(power(mecerror,2));
P1data(i)=sum(harmonic(2:end));
%  figure(i)
%   test(mecerror,xlabledata);
%   hold on
 end
errorout=errorout';
P1data=P1data';