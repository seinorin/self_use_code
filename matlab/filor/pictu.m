function pictu(num1,num2,t)
%用于绘图
% subplot(2,1,1)

% title('仿真滤波误差')
% xlabel('时间（ms）')
% ylabel('幅值（V）')
% subplot(2,1,2)

plot(t*1000,num2,'-')
xlabel('时间（ms）')
ylabel('幅值（V）')
hold on
plot(t*1000,num1,'*')
% title('DA转换误差')
end

