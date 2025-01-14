font_size = 10;
line_width = 1.2;

Ts = 0.02;
Tend = 70;  % 仿真结束的时刻
Nend = Tend/Ts;
t=(1:Nend+1)*Ts;

figure(1)
set(gcf,'color',[1 1 1])
hold on
grid on
plot(t,E_imag(:,2),'r-','linewidth',line_width)
plot(t,E_imag(:,3),'g--','linewidth',line_width)
xlabel('t(s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('image tracking error(ft)','fontsize',font_size,'fontname','Times New Roman')
xlim([0 70])
legend('image tracking error in x axis','image tracking error in y axis')
set(gca,'FontSize',font_size)


figure(2)
set(gcf,'color',[1 1 1])
grid on
plot(t,E_imag(:,1),'linewidth',line_width)
xlabel('t(s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('image tracking error(ft)','fontsize',font_size,'fontname','Times New Roman')
xlim([0 70])
legend('image tracking error in z axis')
set(gca,'FontSize',font_size)


figure(3)
set(gcf,'color',[1 1 1])
hold on
grid on
plot(t,P_dr_pr(:,1),'r-','linewidth',line_width)
plot(t,P_dr_pr(:,2),'g--','linewidth',line_width)
plot(t,P_dr_pr(:,3),'b-.','linewidth',line_width)
xlabel('t(s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('relative distance(m)','fontsize',font_size,'fontname','Times New Roman')
xlim([0 70])
legend('relative distance along x axis','relative distance along y axis','relative distance along z axis')
set(gca,'FontSize',font_size)
% 
% figure(4)
% set(gcf,'color',[1 1 1])
% grid on
% plot3(P_pr(:,1),P_pr(:,2),P_pr(:,3),'r--','linewidth',line_width)
% hold on
% plot3(P_dr(:,1),P_dr(:,2),P_dr(:,3),'g-','linewidth',line_width)
% xlabel('x(m)','fontsize',font_size,'fontname','Times New Roman')
% ylabel('y(m)','fontsize',font_size,'fontname','Times New Roman')
% zlabel('z(m)','fontsize',font_size,'fontname','Times New Roman')
% set(gca,'FontSize',font_size)




