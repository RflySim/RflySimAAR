clear
clc
close all

font_size = 24;
line_width = 1.2;

Ts = 0.1;
TDs = 20;   % 开始对接的时刻
TDe = 30;   % 结束对接的时刻
Tend = 50;  % 仿真结束的时刻
Ttry = TDe - TDs; % 对接用时

NDs = TDs/Ts; 
NDe = TDe/Ts;
Nend = Tend/Ts;

%% 全程内部运算采用指地的z，配合模型F16AirRef_Bowwave2Drogue_v2
load longlatParameters.mat     % 源自F16_v3_longlat.m
load hose_parameter4dock.mat   % 源自Controller3Main_v3_Fb.m
load input_reference.mat       % 源自Input_reference_generateor文件夹，用来产生输入基函数
load('Output_C1.mat')          % 用来绘图对比
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

%% 迭代优化
u_T = zeros(Nend+1,2); % T代表油门
u_e = zeros(Nend+1,2); % e代表升降舵
u_a = zeros(Nend+1,2); % a代表副翼
u_r = zeros(Nend+1,2); % r代表方向舵

for i = 1:Nend+1
    t = (i-1)*Ts;
    u_T(i,1) = t;
    u_e(i,1) = t;
    u_a(i,1) = t;
    u_r(i,1) = t;
end
u_T(1:50/Ts+1,2) = uT_r(:,2);
u_a(1:50/Ts+1,2) = ua_r(:,2);
u_e(1:50/Ts+1,2) = ue_r(:,2);
u_r(1:50/Ts+1,2) = ur_r(:,2);

p0_rcx_r(1,1) = p0_rc(1);
p0_rcy_r(1,1) = p0_rc(2);
p0_rcz_r(1,1) = p0_rc(3);

sim('TILC_AirRef_v1_longlat')
[Value,N_dock]=min(abs(y_TILC_x));     
e_dock(1) = sqrt(y_TILC_y(N_dock)^2+y_TILC_z(N_dock)^2);

figure(1)
set(gcf,'color',[1 1 1])
subplot(2,2,1)
plot(u_T(:,1),y_TILC_x(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-5,7])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('x_d_/_p_,_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,2)
plot(u_T(:,1),y_TILC_y(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.3,1.2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('y_d_/_p_,_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,3)
plot(u_T(:,1),y_TILC_z(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1.4,0.4])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('z_d_/_p_,_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,4)
plot(u_T(:,1),-y_TILC_v(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1.5,0.2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('v_d_/_p_x_,_k(m/s)','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on

figure(2)
set(gcf,'color',[1 1 1])
subplot(2,2,1)
plot(u_T(:,1),u_T(:,2),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-10,100])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_T_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,2)
plot(u_T(:,1),u_a(:,2),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-10,2])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_a_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,3)
plot(u_T(:,1),u_e(:,2),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-5,1.5])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_e_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on
subplot(2,2,4)
plot(u_T(:,1),u_r(:,2),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.5,1.5])
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('u_r_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
hold on
grid on

Np = 9;
k_T = 1;
k_a = 1;
k_e = 1;
k_r = 1;
L_x = 0.9;
L_y = 0.5;
L_z = 0.5;
for j = 1:Np
    disp(j)
    p0_rc(1) = p0_rc(1) + L_x*y_TILC_x(NDe+1);
    p0_rc(2) = p0_rc(2) + L_y*y_TILC_y(NDe+1);
    p0_rc(3) = p0_rc(3) + L_z*y_TILC_z(NDe+1);

    sim('TILC_AirRef_v1_longlat')
    
    figure(1)
    subplot(2,2,1)
    plot(u_T(:,1),y_TILC_x(:,1),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)])
    subplot(2,2,2)
    plot(u_T(:,1),y_TILC_y(:,1),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)])
    subplot(2,2,3)
    plot(u_T(:,1),y_TILC_z(:,1),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)])
    subplot(2,2,4)
    plot(u_T(:,1),-y_TILC_v(:,1),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)])
    figure(2)
    subplot(2,2,1)
    plot(u_T(:,1),u_T(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
    subplot(2,2,2)
    plot(u_T(:,1),u_a(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
    subplot(2,2,3)
    plot(u_T(:,1),u_e(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
    subplot(2,2,4)
    plot(u_T(:,1),u_r(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
   
    p0_rcx_r(j+1,1) = p0_rc(1);
    p0_rcy_r(j+1,1) = p0_rc(2);
    p0_rcz_r(j+1,1) = p0_rc(3);
    
    [Value,N_dock]=min(abs(y_TILC_x));
    e_dock(j+1) = sqrt(y_TILC_y(N_dock)^2+y_TILC_z(N_dock)^2);
%     if e_dock(j+1) < 0.3
%         break;
%     end
end

figure(1)
subplot(2,2,1)
h = legend('k=1','k=2','k=3','k=4');
set(h,'Fontsize',font_size-6);
subplot(2,2,2)
h = legend('k=1','k=2','k=3','k=4');
set(h,'Fontsize',font_size-6);
subplot(2,2,3)
h = legend('k=1','k=2','k=3','k=4');
set(h,'Fontsize',font_size-6);
subplot(2,2,4)
h = legend('k=1','k=2','k=3','k=4');
set(h,'Fontsize',font_size-6);

figure(2)
subplot(2,2,1)
h = legend('k=1','k=2','k=3','k=4','k=5');
set(h,'Fontsize',font_size-6);
subplot(2,2,2)
h = legend('k=1','k=2','k=3','k=4','k=5');
set(h,'Fontsize',font_size-6);
subplot(2,2,3)
h = legend('k=1','k=2','k=3','k=4','k=5');
set(h,'Fontsize',font_size-6);
subplot(2,2,4)
h = legend('k=1','k=2','k=3','k=4','k=5');
set(h,'Fontsize',font_size-6);

figure(4)
set(gca,'FontSize',font_size)
plot(e_dock,'r-','linewidth',line_width)
hold on
plot(e_dock,'ro','linewidth',line_width)
hold off
xlabel('k','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('e_d_o_c_k(m)','fontsize',font_size+5,'fontname','Times New Roman')
grid on 


%% for comparative plot
%%对接误差
e_dock_C2=e_dock;
save('e_dock_C2.mat','e_dock_C2')
