%%实时位置误差(x,y,z)
font_size = 16;
figure(5)
set(gcf,'color',[1 1 1])
hold on
grid on

plot(t,d_pr_dr(:,2),'k','LineStyle', '-', 'LineWidth', 1);
plot(t,d_pr_dr(:,3),'k','LineStyle', '--', 'LineWidth', 1);
plot(t,d_pr_dr(:,1),'k','LineStyle', '-.', 'LineWidth', 1);


xlabel('Time (s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('Relative distance (m)','fontsize',font_size,'fontname','Times New Roman')
axis([0 30 -10 10] )
legend('Relative distance along x axis','Relative distance along y axis','Relative distance along z axis')
set(gca,'FontSize',font_size)