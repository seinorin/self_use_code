function out=getreturn(key,errorout)
%使用的正交表，列为因素，行为实验号
%表头 齿高 对极数 定子圆角 气隙 外径 齿形 材料 定子厚度 频率 error error
  sheet=[
         1 1 2 1 1 2 1 2 2 2 1%1   121
         1 2 1 1 2 1 2 2 2 1 1%2   221
         2 1 1 2 1 2 2 2 1 1 1%3   121
         2 2 2 1 1 1 2 1 1 2 1%4   211
         1 1 1 2 1 1 2 1 2 2 2%5   111
         1 2 2 2 1 1 1 2 1 1 2%6   221
         1 2 1 2 2 2 1 1 1 2 1%7   211
         2 2 1 1 1 2 1 1 2 1 2%8   211
         2 1 2 2 2 1 1 1 2 1 1%9   111
         1 1 2 1 2 2 2 1 1 1 2%10  111
         2 1 1 1 2 1 1 2 1 2 2%11  121
         2 2 2 2 2 2 2 2 2 2 2%12  221
  ];
%正交表有多少行，即多少次实验
n=size(sheet,1);
%正交表的水平数，正交表必须为大于0 的整数,全0为空列
a=max(sheet(:,1));
%获取各个因素的离差平方和
for i=1:a
   sheet1=(sheet==i); 
%    sheet(sheet1)=0;
   sheet1=sheet1.*errorout;
   T(i,:)=sum(sheet1,1)/length(sheet)*a;
%    sheet=sheet+sheet1;
end
y_=sum(errorout)/length(errorout);
SS=sum(power(T-y_,2)*n/a,1);
%各列的自由度
DF=(a-1)*ones(1,size(sheet,2));
%各列的fvalue和p初始化
fandp=zeros(3,size(sheet,2));
%原始的数据分析表
rootdata=[DF;SS;fandp]';
%求误差列数据
error=sum(rootdata(key,:),1);
error(3)=error(2)/error(1);
%模型的数据
source=rootdata;
source(key,:)=[];
model=sum(source,1);
model(3)=model(2)/model(1);
%合计
corrected=error+model;
corrected(3)=0;
%source的均方差
source(:,3)=source(:,2)./source(:,1);
%获取fvalue和p
model(4)=model(3)/error(3);
model(5)=1-fcdf(model(4),model(1),error(1));
source(:,4)=source(:,3)./error(3);
source(:,5)=1-fcdf(source(:,4),source(:,1),error(1));
%输出表
out=[model;error;corrected;source];
