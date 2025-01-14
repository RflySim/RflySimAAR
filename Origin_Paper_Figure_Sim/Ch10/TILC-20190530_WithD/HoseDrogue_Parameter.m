
close all
clear
clc

load('hose_initial.mat')

N = 10;

theta10 = theta1_100; %pi/6*ones(1,N);
theta20 = theta2_100; %zeros(1,N);
dtheta10 = zeros(1,N);
dtheta20 = zeros(1,N);

height = 3000;
vt0 = [120;0;0];
pt0 = [0;0;0];

length = 15;
l_density = 4.1;
l1 = 2;
l0 = (length-l1)/(N-1);
m0 = l0*l_density;
Rl = 0.0336;

Mdr = 29.5;
Rdr = 0.305;
Cdr_ = 0.8;

T_reel_initial = 1610; % 注意该数值与露在外边的软管锥套质量有关，
                       % 若软管锥套的参数调整，需要重新通过v1版的仿真计算
t_step = 100;
k_reel = 0.5;

save('hose_parameter4dock.mat')

%% 如果只看一次系统运行状况 %%
% k_reel = 2; % 这是控制器的系数
% sim('Controller3_v2_Fb.slx')

%% 分析系数k_reel对系统的影响，运行这部分 %%
% Ts = 0.01;
% Tt = 300;
%
% t = 0:Ts:Tt; %t_step-20:Ts:Tt;
% 
% k_reel_set = 0.5; %[0.3,0.5,1,3];
% N_set = size(k_reel_set,2);
% n_step = 1; % t_step/Ts + 1 - 20/Ts; % 比阶跃时间提前10s看，有个对比
% n_total = Tt/Ts + 1;
% 
% rl1_v = zeros(N_set,n_total-n_step+1);
% rT_hose = zeros(N_set,n_total-n_step+1);
% % rT_reel = zeros(N_set,n_total-n_step+1);
% rp_dr_x = zeros(N_set,n_total-n_step+1);
% rp_dr_y = zeros(N_set,n_total-n_step+1);
% rp_dr_z = zeros(N_set,n_total-n_step+1);
% 
% for i = 1:N_set
%     disp('When k_reel = ')
%     disp(k_reel_set(i))
%     
%     k_reel = k_reel_set(i);
%     sim('Controller3_v2_Fb.slx')
%         
%     rl1_v(i,:) = l1_v(n_step:n_total);
%     rT_hose(i,:) = T_hose(n_step:n_total);
% %     rT_reel(i,:) = T_reel(n_step:n_total);
%     rp_dr_x(i,:) = p_dr_x(n_step:n_total);
%     rp_dr_y(i,:) = p_dr_y(n_step:n_total);
%     rp_dr_z(i,:) = p_dr_z(n_step:n_total);
% end
% 
% close all
% line1 = '-';
% line2 = '--';
% line3 = ':';
% line4 = '-.';
% lineC1 = 0.0*[1,1,1];
% lineC2 = 0.3*[1,1,1];
% lineC3 = 0.5*[1,1,1];
% lineC4 = 0.7*[1,1,1];
% linew = 2;
% tmin = 90;
% tmax = 180;
% YFont = 50;
% LegendFont = 56;
% TickFont = 32;
%    
% figure(1)
% set(gcf,'color',[1,1,1])
% plot(t,rT_hose(1,:),line1,'color',lineC1,'linewidth',linew)
% hold on
% grid on
% % plot(t,rT_hose(2,:),line2,'color',lineC2,'linewidth',linew)
% % plot(t,rT_hose(3,:),line3,'color',lineC3,'linewidth',linew)
% % plot(t,rT_hose(4,:),line4,'color',lineC4,'linewidth',linew)
% xlim([tmin tmax])
% set(gca,'fontsize',TickFont) 
% % set(gca,'xtick',100:10:180)
% ylabel('\it{T_h_o_s_e}','fontsize',YFont,'fontname','Times New Roman')
% legend({'{\it{k}} = 0.3','{\it{k}} = 0.5','{\it{k}} = 1','{\it{k}} = 3'},'FontSize',LegendFont,'fontname','Times New Roman')
% 
% figure(2)
% set(gcf,'color',[1,1,1])
% plot(t,rl1_v(1,:),line1,'color',lineC1,'linewidth',linew)
% hold on
% grid on
% % plot(t,rl1_v(2,:),line2,'color',lineC2,'linewidth',linew)
% % plot(t,rl1_v(3,:),line3,'color',lineC3,'linewidth',linew)
% % plot(t,rl1_v(4,:),line4,'color',lineC4,'linewidth',linew)
% xlim([tmin tmax])
% set(gca,'fontsize',TickFont)
% % set(gca,'xtick',100:10:180)
% ylabel('\it{l_1}','fontsize',YFont,'fontname','Times New Roman')
% 
% figure(3)
% set(gcf,'color',[1,1,1])
% plot(t,rp_dr_x(1,:),line1,'color',lineC1,'linewidth',linew)
% hold on
% grid on
% % plot(t,rp_dr_x(2,:),line2,'color',lineC2,'linewidth',linew)
% % plot(t,rp_dr_x(3,:),line3,'color',lineC3,'linewidth',linew)
% % plot(t,rp_dr_x(4,:),line4,'color',lineC4,'linewidth',linew)
% xlim([tmin tmax])
% ylim([-14.4 -13.6])
% set(gca,'fontsize',TickFont)
% % set(gca,'xtick',100:10:180)
% ylabel('\it{p_d_x}','fontsize',YFont,'fontname','Times New Roman')
% 
% figure(4)
% set(gcf,'color',[1,1,1])
% plot(t,rp_dr_z(1,:),line1,'color',lineC1,'linewidth',linew)
% hold on
% grid on
% % plot(t,rp_dr_z(2,:),line2,'color',lineC2,'linewidth',linew)
% % plot(t,rp_dr_z(3,:),line3,'color',lineC3,'linewidth',linew)
% % plot(t,rp_dr_z(4,:),line4,'color',lineC4,'linewidth',linew)
% xlim([tmin tmax])
% ylim([4.8 5.5])
% set(gca,'fontsize',TickFont)
% % set(gca,'xtick',100:10:180)
% ylabel('\it{p_d_z}','fontsize',YFont,'fontname','Times New Roman')
% xlabel('\it{t}','fontsize',YFont,'fontname','Times New Roman')
% 
% theta1_100 = theta1(100/Ts,:);
% theta2_100 = theta2(100/Ts,:);
