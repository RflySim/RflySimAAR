set(gcf,'color',[1 1 1])
plot3(actual_trajectory.signals.values(:,1),actual_trajectory.signals.values(:,2),actual_trajectory.signals.values(:,3),'linewidth',2)
grid on
xlabel('x(m)','fontsize',14,'fontname','Times New Roman')
ylabel('y(m)','fontsize',14,'fontname','Times New Roman')
zlabel('h(m)','fontsize',14,'fontname','Times New Roman')
set(gca,'FontSize',14)
xlim([-70,0]);
ylim([-60,10]);    %%%��ͼ�е�y���������ǽ�����y���귽���෴
zlim([0,10]);