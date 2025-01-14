clear
clc
close all

font_size = 24;
line_width = 1.5;

Ts = 0.1;
TDs = 20;   % 开始对接的时刻
TDe = 30;   % 结束对接的时刻
Tend = 100;  % 仿真结束的时刻
Ttry = TDe - TDs; % 对接用时

NDs = TDs/Ts; 
NDe = TDe/Ts;
Nend = Tend/Ts;

%% 全程内部运算采用指地的z，配合模型F16AirRef_Bowwave2Drogue_v2
load longlatParameters.mat     % 源自F16_v3_longlat.m
% load hose_parameter4dock.mat   % 源自Controller3Main_v3_Fb.m
% run BWLinearize

% A1 = [Adr,zeros(4,6);zeros(6,4),A_k];
% B1 = [Bdr,zeros(4,2);zeros(6,2),B_];    % 注意这里油门量调整过了，用的是乘以1000以后的输入
% C1 = [Cdr,-C_rcO(1:2,:);[0 0 0 0],Cv];
n_n_dr = size(Adr,1);
n_l_dr = size(Bdr,2);
n_m_dr = size(Cdr,1);
n_n_rc = size(Arc,1);
n_l_rc = size(Brc,2);
n_m_rc = size(Crc,1);

A = [Adr,zeros(n_n_dr,n_n_rc);zeros(n_n_rc,n_n_dr),Arc];
B = [Bdr,zeros(n_n_dr,n_l_rc);zeros(n_n_rc,n_l_dr),Brc]; % 注意这里油门量调整过了，用的是乘以1000以后的输入
C = [[Cdr;zeros(1,n_n_dr)],-Crc];

d_pr_rc = [6.06;0.54;-0.86];
d_f_rc = [3.86;0;-0.86];
p0_rc = [-14.35-6.06-6;-0.54-1;5.12+0.86+1]; % [锥套位置+锥管位置+占位位置;锥管位置+占位位置;锥套位置+锥管位置+占位位置]
p0_pr = p0_rc + d_pr_rc;
p0_dr = [-14.35;0;5.12];
d0_dr_pr = p0_dr - p0_pr;

%% 本程序重点：产生一条合理的轨迹 %%
u_T = zeros(Nend+1,2); % T代表油门
u_a = zeros(Nend+1,2); % a代表副翼
u_e = zeros(Nend+1,2); % e代表升降舵
u_r = zeros(Nend+1,2); % r代表方向舵
u_Ideal_x = zeros(Nend+1,2); % 用来产生参考轨迹的参考输入
u_Ideal_y = zeros(Nend+1,2);
u_Ideal_z = zeros(Nend+1,2);
u_ex = zeros(Nend+1,2);  % 伴随系统的输入(暂定3个输入，xyz，如有增加，这里得改)
u_ey = zeros(Nend+1,2);
u_ez = zeros(Nend+1,2);
for i = 1:Nend+1
    t = (i-1)*Ts;
    u_T(i,1) = t;
    u_a(i,1) = t;
    u_e(i,1) = t;
    u_r(i,1) = t;
    u_Ideal_x(i,1) = t;
    u_Ideal_y(i,1) = t;
    u_Ideal_z(i,1) = t;
    u_ex(i,1) = t;
    u_ey(i,1) = t;
    u_ez(i,1) = t;
end

x_tempt = 1;
y_tempt = 1;
z_tempt = 1;
x_goal_T = d0_dr_pr(1);  % 要消除的位置正好是锥套-锥管位置
y_goal_T = d0_dr_pr(2);
z_goal_T = d0_dr_pr(3);
k_overshoot = 8; % 由时间延伸而规划出的速度超调

for i = 1:20    % 这里的迭代只是为了产生一个可以直接到达锥套现在位置的标准轨迹
    sim('IdealTrackGenerator')
    e_x = x_goal_T - Ideal_x(NDe,1); % 注意这里为了让x方向速度产生超调，必须用对接的那个时刻
    e_y = y_goal_T - Ideal_y(NDe,1);
    e_z = z_goal_T - Ideal_z(NDe,1);
    x_tempt = x_tempt + 0.01*e_x;     %% 优化峰值
    y_tempt = y_tempt + 0.05*e_y;
    z_tempt = z_tempt + 0.05*e_z;   
end

u_Ideal_x(:,2) = Ideal_x;  %最终产生的参考轨迹作为优化基函数的输入
u_Ideal_y(:,2) = Ideal_y;
u_Ideal_z(:,2) = Ideal_z;

figure(1)
set(gcf,'color',[1 1 1])
subplot(2,2,1)
plot(u_T(:,1),u_Ideal_x(:,2),'b','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1,12])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('x_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,2)
plot(u_T(:,1),u_Ideal_y(:,2),'b','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.2,1.2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('y_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,3)
plot(u_T(:,1),u_Ideal_z(:,2),'b','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1.2,0.2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('z_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,4)
plot(u_T(:,1),Ideal_v(:,1),'b','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.2,1.5])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('v_x_,_k(m/s)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on

% 优化参考输入 %%

flag_x = 1;
flag_y = 1;
flag_z = 1;
Np = 20;
for i = 1:Np
    sim('Adjoint_MIMO');    %得到对接误差
    
    u_ex(:,2) = flipud(Ideal_ex);
    u_ey(:,2) = flipud(Ideal_ey);
    u_ez(:,2) = flipud(Ideal_ez);
    
    sim('Adjoint_MIMO_supp');
    Gs_e1_ = flipud(Gs_e1);
    Gs_e2_ = flipud(Gs_e2);
    Gs_e3_ = flipud(Gs_e3);
    Gs_e4_ = flipud(Gs_e4);
        
    alpha = ILC_bk(Nend+1,1)/ILC_ak(Nend+1,1);
    
    u_T(:,2) = u_T(:,2) + alpha*Gs_e1_;
    u_a(:,2) = u_a(:,2) + alpha*Gs_e2_; 
    u_e(:,2) = u_e(:,2) + alpha*Gs_e3_;
    u_r(:,2) = u_r(:,2) + alpha*Gs_e4_;
    
    if i == 2
        figure(1)
        subplot(2,2,1)
        plot(u_T(:,1),Actual_x(:,1),'--','color',[0.2,0.2,0.2])
        subplot(2,2,2)
        plot(u_T(:,1),Actual_y(:,1),'--','color',[0.2,0.2,0.2])
        subplot(2,2,3)
        plot(u_T(:,1),Actual_z(:,1),'--','color',[0.2,0.2,0.2])
        subplot(2,2,4)
        plot(u_T(:,1),Actual_v(:,1),'--','color',[0.2,0.2,0.2])
    end
    
    if i == 5
        figure(1)
        subplot(2,2,1)
        plot(u_T(:,1),Actual_x(:,1),'-.','color',[0.4,0.4,0.4])
        subplot(2,2,2)
        plot(u_T(:,1),Actual_y(:,1),'-.','color',[0.4,0.4,0.4])
        subplot(2,2,3)
        plot(u_T(:,1),Actual_z(:,1),'-.','color',[0.4,0.4,0.2])
        subplot(2,2,4)
        plot(u_T(:,1),Actual_v(:,1),'-.','color',[0.4,0.4,0.4])
    end
    
    if i == 20
        figure(1)
        subplot(2,2,1)
        plot(u_T(:,1),Actual_x(:,1),'color',[0,0,0])
        subplot(2,2,2)
        plot(u_T(:,1),Actual_y(:,1),'color',[0,0,0])
        subplot(2,2,3)
        plot(u_T(:,1),Actual_z(:,1),'color',[0,0,0])
        subplot(2,2,4)
        plot(u_T(:,1),Actual_v(:,1),'color',[0,0,0])
    end
    
    clc;
    disp(i);
end
figure(1)
subplot(2,2,1)
h = legend('k=d','k=2','k=5','k=20');
set(h,'Fontsize',font_size-6);
subplot(2,2,2)
h = legend('k=d','k=2','k=5','k=20');
set(h,'Fontsize',font_size-6);
subplot(2,2,3)
h = legend('k=d','k=2','k=5','k=20');
set(h,'Fontsize',font_size-6);
subplot(2,2,4)
h = legend('k=d','k=2','k=5','k=20');
set(h,'Fontsize',font_size-6);

figure(3)        %迭代学习产生的外环输入
set(gcf,'color',[1 1 1])
subplot(2,2,1)
plot(u_T(:,1),u_T(:,2),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-10,90])
% xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_T_,_b_a_r','fontsize',font_size+5,'fontname','Times New Roman')
grid on
subplot(2,2,2)
plot(u_T(:,1),u_a(:,2),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-10,2])
% xlabel('t(s)',font_size+5,'fontname','Times New Roman')
ylabel('u_a_,_b_a_r','fontsize',font_size+5,'fontname','Times New Roman')
grid on
subplot(2,2,3)
plot(u_T(:,1),u_e(:,2),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-5,2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_e_,_b_a_r','fontsize',font_size+5,'fontname','Times New Roman')
grid on
subplot(2,2,4)
plot(u_T(:,1),u_r(:,2),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.5,1.5])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_r_,_b_a_r','fontsize',font_size+5,'fontname','Times New Roman')
grid on



figure(4)    %对应的内环输入
set(gcf,'color',[1 1 1])
subplot(2,2,1)
plot(u_T(:,1),delta_T(:,1),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-700,700])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('\delta_T(N)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,2)
plot(u_T(:,1),delta_e(:,1),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.02,0.04])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('\delta_e(degree)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,3)
plot(u_T(:,1),delta_a(:,1),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.1,0.1])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('\delta_a(degree)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,4)
plot(u_T(:,1),delta_r(:,1),'k','linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.1,0.1])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('\delta_r(degree)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on


uT_r = u_T(1:50/Ts+1,:);
ua_r = u_a(1:50/Ts+1,:);
ue_r = u_e(1:50/Ts+1,:);
ur_r = u_r(1:50/Ts+1,:);

save('input_reference.mat','uT_r','ua_r','ue_r','ur_r')


