function test(R,t)
%图5

% set(gca,'FontName','Times New Roman','FontSize',9,'LineWidth',0.5);


% set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
% legend('FontName',['宋体' '宋体' 'Times new roman'],'FontSize',9,'LineWidth',0.5);%图例中字体及大小
% legend(['\fontname{宋体}调制波\fontname{宋体}载波\fontname{Times new roman}SPWM']);
% legend('调制波','载波','SPWM','location','northEast');
% k=4500-2000*i;
set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
% t=0:k/(length(R)-1):k;
% i=0:9:360-9;
bar(R)
% ylim([min(R(20,:))-1,max(R(20,:))+1])
xlabel(['\fontname{宋体}谐波频次\fontname{Times new roman}'],'FontSize',9);
ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(mv)'],'FontSize',9);
set(gca,'FontName','Times New Roman','FontSize',9,'LineWidth',0.5);