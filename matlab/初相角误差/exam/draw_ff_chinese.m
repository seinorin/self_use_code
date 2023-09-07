function y=napssz_outsort(ms,ns)%%ms为所求频次，
ms=15;
% clear all;
fid=fopen('角度测量误差.txt');%只读的形式打开文件
R=fscanf(fid,'%f',inf);%读取文件中的所有元素
fclose(fid);%关闭文件
m=length(R);
% z=R(1:m-1);%剔除误差数据中最后一个数据
z=R(1:m);%剔除误差数据中最后一个数据
n=length(z);
z1=fft(z,n);%fft变换
A=2*abs(z1)/n;%求模(交流分量)
A(1)=(z1(1))/n;%直流分量
% P=angle(z1)+pi/2;%求相位
P=angle(z1);%求相位
for i=1:(n/2)
    O(i)=i;
end  
O=O';
for k=2:(n/2+1)
    BA(k-1)=A(k);
    BP(k-1)=P(k);
end
BA=BA';
BP=BP';
B=[BA BP O];
% B=-sortrows(-B);%对1次以后的数值进行降序排序
% AP=[A(1) P(1) 0 ;B;];%排序后的A和P数组
% for j=1:(n/2+1)
%    NapOut(j,1)=AP(j,3);
%    NapOut(j,2)=AP(j,1);
%    NapOut(j,3)=AP(j,2);
% end

AP=[A(1) P(1) 0 ;B;];%未排序后的A和P数组
for j=1:(n/2+1)
   NapOut(j,1)=AP(j,3);
   NapOut(j,2)=AP(j,1);
   NapOut(j,3)=AP(j,2);
end

fid=fopen('傅里叶变换结果.txt','wt');
for i=1:ms
%     fprintf(fid,'c%d[%d]=%d;\t\ta%d[%d]=%f;\t\tb%d[%d]=%f\n',ns,i-1,NapOut(i,1),ns,i-1,NapOut(i,2),ns,i-1,NapOut(i,3));
    fprintf(fid,'%d\t%f\t%f\n',NapOut(i,1),NapOut(i,2),NapOut(i,3));
end
fclose(fid);%关闭文件

%data=load('fitssz_outsort.txt');
%x=data(:,1);
%y=data(:,2);
%stem(x,y);
t=[0:1:14]%t=[0:1/fs:N/fs]; %采样时刻
X=load('傅里叶变换结果.txt');
S=X(:,2); %信号
stem(t,S);

set(gcf,'unit','centimeters','position',[0 0 12 6.5]);%单位为厘米，大小为16cm×6.5cm，图形起点坐标为（0cm，0cm）表示左下点离显示器左侧边界0cm，离下侧边界0cm。
xlabel('谐波频次');
ylabel('幅值[″]');
set(gca,'FontName','Times New Roman','FontSize',12)%设置坐标轴字体大小，字型
xlabel('谐波频次','Fontname', 'Times New Roman','FontSize',12);
ylabel('幅值[″]','Fontname', 'Times New Roman','FontSize',12);
%title('The harmonic order(Hz)');
grid on;