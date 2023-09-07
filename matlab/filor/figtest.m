%图1
set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
legend('FontName','Times new roman','FontSize',9,'LineWidth',0.5);%图例中字体及大小
% legend(['\fontname{宋体}调制波\fontname{宋体}载波\fontname{Times new roman}SPWM']);
legend('DAC','SPWM','location','northEast');
xlabel(['\fontname{宋体}频率\fontname{Times new roman}(Hz)'],'FontSize',9);
ylabel(['\fontname{宋体}幅值'],'FontSize',9);
set(gca,'FontName','Times New Roman','FontSize',9,'LineWidth',0.5);


% %图5
% set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
% set(gca,'FontName','Times New Roman','FontSize',9,'LineWidth',0.5);

%图1
% set(gcf,'unit','centimeters','position',[10 5 7 5]);%设置图片大小
% legend('FontName',['宋体' '宋体' 'Times new roman'],'FontSize',9,'LineWidth',0.5);%图例中字体及大小
% % legend(['\fontname{宋体}调制波\fontname{宋体}载波\fontname{Times new roman}SPWM']);
% legend('调制波','载波','SPWM','location','northEast');
% 
% xlabel(['\fontname{宋体}时间\fontname{Times new roman}(μs)'],'FontSize',9);
% ylabel(['\fontname{宋体}幅值\fontname{Times new roman}(V)'],'FontSize',9);
% set(gca,'FontName','Times New Roman','FontSize',9,'LineWidth',0.5);



