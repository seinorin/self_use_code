clc,clear;

%用于采集的数据
%200us 4096
u2003=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\n=3_5.txt').data;%取这个
fpga_200us=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\fpga_200us.txt').data;
%100us 4096
fpga_100us=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\fpga_100us.txt').data;
u1002=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\n=3_7.txt').data;%取这个
%50us 4096
u501=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\n=3_8.txt').data;%取这个
fpga_50us=importdata('C:\Users\Lenovo\Desktop\paper\滤波电路\fpga_50us.txt').data;

% out1=-u501(851:3350);
% plot(out1)
% out=fpga_200us(480:1104);
% plot(out)
% 
% 
% 

% % % %实际信号的频谱
hznum=10000;
% set(gcf,'unit','centimeters','position',[10 5 7 12.9])
% subplot(3,1,1)
set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
[t,out]=ntimenum(fpga_200us);
[t,out]=zqtz(out,1000,t);
[f1,p1]=fget(out*10,t/1000);
semilogx(f1(2:end),p1(2:end))
% % title('DA-200us')
xlabel(['\fontname{宋体}频率\fontname{Times new roman}(Hz)'],'FontSize',9);
ylabel(['\fontname{宋体}幅值'],'FontSize',9);
hold on
% subplot(3,1,1)
[t,out]=ntimenum(u2003);
[t,out]=zqtz(out,1000,t);
[f1,p1]=fget(out,t/1000);
semilogx(f1(2:end),p1(2:end))
% % title('SPWM-200us')
% xlabel('频率（hz）')
% ylabel('幅值')
% subplot(3,1,2)
% [t,out]=ntimenum(fpga_100us);
% [t,out]=zqtz(out,1000,t);
% [f1,p1]=fget(out*10,t/1000);
% plot(f1(2:hznum),p1(2:hznum))
% % title('DA-100us')
% xlabel('频率（hz）')
% ylabel('幅值')
% hold on
% subplot(3,1,2)
% [t,out]=ntimenum(u1002);
% [t,out]=zqtz(out,2000,t);
% [f1,p1]=fget(out,t/1000);
% plot(f1(2:hznum),p1(2:hznum))
% % title('SPWM-100us')
% xlabel('频率（hz）')
% ylabel('幅值')
% subplot(3,1,3)
% [t,out]=ntimenum(fpga_50us);
% [t,out]=zqtz(out,1000,t);
% [f1,p1]=fget(out*10,t/1000);
% plot(f1(2:hznum),p1(2:hznum))
% % title('DA-50us')
% xlabel('频率（hz）')
% ylabel('幅值')
% hold on
% subplot(3,1,3)
% [t,out]=ntimenum(u501);
% [t,out]=zqtz(out,5000,t/2000);
% [f1,p1]=fget(out,t);
% plot(f1(2:hznum),p1(2:hznum))
% % title('SPWM-50us')
% xlabel('频率（hz）')
% ylabel('幅值')

% 
% % 
% % % 几种信号的图案10
% % 
% set(gcf,'unit','centimeters','position',[10 5 7 12.9])
% subplot(3,1,1)
% [t,out]=ntimenum(fpga_200us);
% plot(t,out*10,'-')
% % % title('DA-200us')
% xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
% ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(ms)'],'FontSize',9);
% hold on
% subplot(3,1,1)
% [t,out]=ntimenum(u2003);
% plot(t,out*10,'-.')
% % % title('SPWM-200us')
% xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
% ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
% subplot(3,1,2)
% [t,out]=ntimenum(fpga_100us);
% plot(t,out,'-')
% % % title('DA-100us')
% hold on
% subplot(3,1,2)
% [t,out]=ntimenum(u1002);
% plot(t,out*10,'-.')
% % % title('SPWM-100us')
% k1=2600;k2=2300;
% xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
% ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
% subplot(3,1,3)
% [t,out]=ntimenum(fpga_50us);
% plot(t(1:k1)/4*1.1,out(1:k1),'-')
% % % title('DA-50us')
% hold on
% subplot(3,1,3)
% [t,out]=ntimenum(u501);
% plot(t(1:k2)/2*1.1,out(1:k2)*10,'-.')
% % % title('SPWM-50us')
% xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
% ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);


% plot(fpga_200us*10);hold on;
% plot(fpga_100us);hold on;
% plot(fpga_50us);hold on;
% plot(u1002*10);hold on;
% plot(u2003*10);hold on;
% plot(u501*10);hold on;