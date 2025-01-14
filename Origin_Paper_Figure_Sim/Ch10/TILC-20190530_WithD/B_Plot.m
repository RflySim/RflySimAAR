font_size = 14;
line_width = 1;

load e_dock_C3
load e_dock_C3_B1
load e_dock_C3_B2
load e_dock_C3_B3
load e_dock_C3_B4

figure(1)
set(gca,'FontSize',font_size)
xlabel('k','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('e_d_o_c_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
plot(e_dock_C3,'-*','linewidth',line_width)
hold on
plot(e_dock_C3_B1,'-+','linewidth',line_width)
plot(e_dock_C3_B2,'-o','linewidth',line_width)
plot(e_dock_C3_B3,'-s','linewidth',line_width)
plot(e_dock_C3_B4,'-x','linewidth',line_width)
legend('Normal','Uncertainty factor = 0.6','Uncertainty factor = 0.8','Uncertainty factor = 1.2','Uncertainty factor = 1.4')
hold off
grid on 