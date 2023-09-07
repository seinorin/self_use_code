clc,clear;

%正弦
N=5000;%一个周期细分度
T=10;%周期数
t=(0:2/N*pi:2*T*pi)/4000/pi;%两个周期1ms
[rootnum,angular,spwm1,danum1]=getroot(t,50,960);%原始数据
[rootnum,angular,spwm2,danum2]=getroot(t,25,480);%原始数据
[rootnum,angular,spwm3,danum3]=getroot(t,12,240);%原始数据
%t=t*1000;
% plot(t,danum1,t,danum2,t,danum3);
% xlabel("时间(ms)")
% ylabel("幅值(V)")
out1=butf(spwm1,t)';%滤波
fin1=onef(out1,N);%取一个周期数据,
out2=butf(spwm2,t)';%滤波
fin2=onef(out2,N);%取一个周期数据,
out3=butf(spwm3,t)';%滤波
fin3=onef(out3,N);%取一个周期数据,




%单周期误差比较不晓得是图几
set(gcf,'unit','centimeters','position',[10 5 7 12.9])
subplot(3,1,3)
plot(t(1:N)*1000,fin1-onef(rootnum,N))
hold on
a0=t(1:N)*1000;a=[];
b0=onef(rootnum,N)-onef(danum1,N);b=[];
for i=1:50:length(b0)
    a=[a a0(i)];
    b=[b b0(i)];
end
plot(a,b,'-.')
% title("c")
xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
subplot(3,1,2)
a0=t(1:N)*1000;a=[];
b0=onef(rootnum,N)-onef(danum2,N);b=[];
for i=1:50:length(b0)
    a=[a a0(i)];
    b=[b b0(i)];
end
plot(a,b,'-.')
hold on
plot(t(1:N)*1000,fin2-onef(rootnum,N))
% title("b")
xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
subplot(3,1,1)
plot(t(1:N)*1000,fin3-onef(rootnum,N))
hold on
a0=t(1:N)*1000;a=[];
b0=onef(rootnum,N)-onef(danum3,N);b=[];
for i=1:50:length(b0)
    a=[a a0(i)];
    b=[b b0(i)];
end
plot(a,b,'-.')
% title("a")
xlabel(['\fontname{宋体}时间\fontname{Times new roman}(ms)'],'FontSize',9);
ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
% % % plot(onef(danum,N)-onef(rootnum,N))

% 
% %图8
% set(gcf,'unit','centimeters','position',[10 5 7 4.3])
% a0=fin1-onef(rootnum,N);a=[];
% b0=onef(danum1,N)-onef(rootnum,N);b=[];
% c0=t(1:N);c=[];
% for i=1:50:length(c0)
%     a=[a a0(i)];
%     b=[b b0(i)];
%     c=[c c0(i)];
% end
% pictu(a,b,c)
% 

% % SPWM与DA的频域特性
% [f1,p1]=fget(spwm1,t);
% [f2,p2]=fget(danum,t);
% set(gcf,'unit','centimeters','position',[10 5 7 8.6])
% subplot(2,1,1)
% plot(f1(2:end),p1(2:end))
% semilogx(f1(2:end),p1(2:end))
% % title("a")
% xlabel('频率（hz）')
% ylabel('幅值')
% % subplot(2,2,2)
% % plot(f1(2:end),p1(2:end))
% % title("b")
% % xlabel('频率（hz）')
% % ylabel('幅值')
% subplot(2,1,2)
% semilogx(f2(2:end),p2(2:end))
% % title("c")
% xlabel('频率（hz）')
% ylabel('幅值')
% % subplot(2,2,4)
% % plot(f2(2:end),p2(2:end))
% % title("d")
% % xlabel('频率（hz）')
% % ylabel('幅值')


% % 图9
% set(gcf,'unit','centimeters','position',[10 5 7 4.3])
% [f1,p1]=fget(out1,t);
% % subplot(2,1,1)
% semilogx(f1(2:end),p1(2:end),'.')
% % title("a")
% xlabel('频率（hz）')
% ylabel('幅值')
% % subplot(2,1,2)
% % semilogx(f1(2:end),p1(2:end))
% % title("b")
% % xlabel('频率（hz）')
% ylabel('幅值')