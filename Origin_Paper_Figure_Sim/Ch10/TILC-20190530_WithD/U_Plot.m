font_size = 14;
line_width = 1;

load e_dock_C3
load e_dock_C3_U1
load e_dock_C3_U2


% figure(1)
% set(gca,'FontSize',font_size)
% xlabel('k','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('e_d_o_c_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
% plot(e_dock_C3,'k:*','linewidth',line_width)
% hold on
% plot(e_dock_C3_U1,'b--+','linewidth',line_width)
% plot(e_dock_C3_U2,'r-o','linewidth',line_width)
% legend('Normal','With uncertiantys and disturbances (i), (ii), (iii)','With uncertiantys and disturbances (i), (ii), (iii), (iv)')
% hold off
% grid on 

figure(2)
set(gca,'FontSize',font_size)
xlabel('k','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('e_d_o_c_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
plot(e_dock_C3,'k:*','linewidth',line_width)
hold on
plot(e_dock_C3_U2,'r-o','linewidth',line_width)
legend('Normal','With uncertiantys and disturbances')
hold off
grid on