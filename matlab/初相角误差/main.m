clc,clear
%计算的结果值。
[errorout,P1data]=getoutdata();
out=getreturn([10 11],errorout);
% out=getreturn([1 5 8 10 11],P1data);
a=roundn(out,-2);

%1-fcdf(num,p1,p2)
%求p值，num为统计量值，p1，p1为待求值与误差的自由度
% plot(xlabledata,error)
