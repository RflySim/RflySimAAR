clear
clc
close all

font_size = 10;
line_width = 1;

Ts = 0.1;
TDs = 20;   % ��ʼ�Խӵ�ʱ��
TDe = 30;   % �����Խӵ�ʱ��
Tend = 50;  % ���������ʱ��
Ttry = TDe - TDs; % �Խ���ʱ

NDs = TDs/Ts; 
NDe = TDe/Ts;
Nend = Tend/Ts;

%% ȫ���ڲ��������ָ�ص�z�����ģ��F16AirRef_Bowwave2Drogue_v2
load longlatParameters.mat     % Դ��F16_v3_longlat.m
load hose_parameter4dock.mat   % Դ��Controller3Main_v3_Fb.m
load input_reference.mat       % Դ��Input_reference_generateor�ļ��У������������������

n_n_dr = size(Adr,1);
n_l_dr = size(Bdr,2);
n_m_dr = size(Cdr,1);
n_n_rc = size(Arc,1);
n_l_rc = size(Brc,2);
n_m_rc = size(Crc,1);

% �����������õ���׶�׺ͼ��ͻ��Ļ��ģ�ͣ�
A = [Adr,zeros(n_n_dr,n_n_rc);zeros(n_n_rc,n_n_dr),Arc];
B = [Bdr,zeros(n_n_dr,n_l_rc);zeros(n_n_rc,n_l_dr),Brc]; % ע��������������׼������
C = [[Cdr;zeros(1,n_n_dr)],-Crc];

d_pr_rc = [6.06;0.54;-0.86];
d_f_rc = [3.86;0;-0.86];
p0_rc = [-14.35-6.06-6;-0.54-1;5.12+0.86+1];
p0_pr = p0_rc + d_pr_rc;
p0_dr = [-14.35;0;5.12];
d0_dr_pr = p0_dr - p0_pr;

%% �����Ż�
u_T = zeros(Nend+1,2); % T��������
u_e = zeros(Nend+1,2); % e����������
u_a = zeros(Nend+1,2); % a������
u_r = zeros(Nend+1,2); % r�������

for i = 1:Nend+1
    t = (i-1)*Ts;
    u_T(i,1) = t;
    u_e(i,1) = t;
    u_a(i,1) = t;
    u_r(i,1) = t;
end
u_T(1:50/Ts+1,2) = uT_r(:,2);     %jr% uT_r���ǻ�����
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
% set(gcf,'color',[1 1 1])
subplot(2,2,1)
% plot(u_T(:,1),y_TILC_x(:,1), 'Color', [0 0 0],'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-5,7])
xlabel('Time(s)','fontsize',font_size)
ylabel('$x_{d/p,k}(m)$','fontsize',font_size,'Interpreter', 'latex')
hold on
grid on
subplot(2,2,2)
% plot(u_T(:,1),y_TILC_y(:,1), 'Color', [0 0 0],'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-0.5,1.2])
xlabel('Time(s)','fontsize',font_size)
ylabel('$y_{d/p,k}(m)$','fontsize',font_size,'Interpreter', 'latex')
hold on
grid on
subplot(2,2,3)
% plot(u_T(:,1),y_TILC_z(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1.5,0.6])
xlabel('Time(s)','fontsize',font_size)
ylabel('$z_{d/p,k}(m)$,','fontsize',font_size,'Interpreter', 'latex')
hold on
grid on
subplot(2,2,4)
% plot(u_T(:,1),-y_TILC_v(:,1),'linewidth',line_width)
set(gca,'FontSize',font_size)
xlim([0,50])
set(gca,'XTick',0:10:50) 
ylim([-1.5,0.2])
xlabel('Time(s)','fontsize',font_size)
ylabel('$v_{dx/p,k}(m/s)$','fontsize',font_size,'Interpreter', 'latex')
hold on
grid on

% figure(2)
% set(gcf,'color',[1 1 1])
% subplot(2,2,1)
% plot(u_T(:,1),u_T(:,2),'linewidth',line_width)
% set(gca,'FontSize',font_size)
% xlim([0,50])
% set(gca,'XTick',0:10:50) 
% ylim([-10,90])
% xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('u_T_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
% hold on
% grid on
% subplot(2,2,2)
% plot(u_T(:,1),u_a(:,2),'linewidth',line_width)
% set(gca,'FontSize',font_size)
% xlim([0,50])
% set(gca,'XTick',0:10:50) 
% ylim([-13,2])
% xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('u_a_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
% hold on
% grid on
% subplot(2,2,3)
% plot(u_T(:,1),u_e(:,2),'linewidth',line_width)
% set(gca,'FontSize',font_size)
% xlim([0,50])
% set(gca,'XTick',0:10:50) 
% ylim([-9,0.5])
% xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('u_e_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
% hold on
% grid on
% subplot(2,2,4)
% plot(u_T(:,1),u_r(:,2),'linewidth',line_width)
% set(gca,'FontSize',font_size)
% xlim([0,50])
% set(gca,'XTick',0:10:50) 
% ylim([-0.5,1.5])
% xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('u_r_,_b_a_r_,_k','fontsize',font_size+5,'fontname','Times New Roman')
% hold on
% grid on

Np = 3;
k_T = 1;
k_a = 1;
k_e = 1;
k_r = 1;
L_T = 0.1;
L_a = -0.4;
L_e = -1;
L_r = 14;

L_x = 0.3;
L_y = 0.4;
L_z = 0.4;
for j = 1:Np
    disp(j)
    k_T = k_T + L_T*y_TILC_x(NDe+1);
    k_a = k_a + L_a*y_TILC_y(NDe+1);
    k_e = k_e + L_e*y_TILC_z(NDe+1);
    k_r = k_r + L_r*y_TILC_y(NDe+1);
    
    u_T(:,2) = k_T*uT_r(:,2);
    u_a(:,2) = k_a*ua_r(:,2);
    u_e(:,2) = k_e*ue_r(:,2);
    u_r(:,2) = k_r*ur_r(:,2);
    
    p0_rc(1) = p0_rc(1) + L_x*y_TILC_x(NDe+1);
    p0_rc(2) = p0_rc(2) + L_y*y_TILC_y(NDe+1);
    p0_rc(3) = p0_rc(3) + L_z*y_TILC_z(NDe+1);
    sim('TILC_AirRef_v1_longlat')

    if j==1
    figure(1)
    subplot(2,2,1)
    plot(u_T(:,1),y_TILC_x(:,1),'LineStyle','-','color',[0,0,0],'linewidth',line_width)
    subplot(2,2,2)
    plot(u_T(:,1),y_TILC_y(:,1),'LineStyle','-','color',[0,0,0],'linewidth',line_width)
    subplot(2,2,3)
    plot(u_T(:,1),y_TILC_z(:,1),'LineStyle','-','color',[0,0,0],'linewidth',line_width)
    subplot(2,2,4)
    plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle','-','color',[0,0,0],'linewidth',line_width)
    
% plot(u_T(:,1),y_TILC_x(:,1),'LineStyle','-','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,2)
%     plot(u_T(:,1),y_TILC_y(:,1),'LineStyle','-','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,3)
%     plot(u_T(:,1),y_TILC_z(:,1),'LineStyle','-','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,4)
%     plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle','-','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)

    end
    if j==2
        figure(1)
%         subplot(2,2,1)
%         plot(u_T(:,1),y_TILC_x(:,1),'LineStyle','-.','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,2)
%         plot(u_T(:,1),y_TILC_y(:,1),'LineStyle','-.','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,3)
%         plot(u_T(:,1),y_TILC_z(:,1),'LineStyle','-.','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,4)
%         plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle','-.','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
    subplot(2,2,1)
        plot(u_T(:,1),y_TILC_x(:,1),'LineStyle','-.','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,2)
        plot(u_T(:,1),y_TILC_y(:,1),'LineStyle','-.','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,3)
        plot(u_T(:,1),y_TILC_z(:,1),'LineStyle','-.','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,4)
        plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle','-.','color',[0,0,0],'linewidth',line_width)
    
    end
    if j==3
        figure(1)
%         subplot(2,2,1)
%         plot(u_T(:,1),y_TILC_x(:,1),'LineStyle',':','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,2)
%         plot(u_T(:,1),y_TILC_y(:,1),'LineStyle',':','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,3)
%         plot(u_T(:,1),y_TILC_z(:,1),'LineStyle',':','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%         subplot(2,2,4)
%         plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle',':','color',[0,0,0],[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
   subplot(2,2,1)
        plot(u_T(:,1),y_TILC_x(:,1),'LineStyle',':','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,2)
        plot(u_T(:,1),y_TILC_y(:,1),'LineStyle',':','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,3)
        plot(u_T(:,1),y_TILC_z(:,1),'LineStyle',':','color',[0,0,0],'linewidth',line_width)
        subplot(2,2,4)
        plot(u_T(:,1),-y_TILC_v(:,1),'LineStyle',':','color',[0,0,0],'linewidth',line_width)
    
    end



    %     figure(2)
%     subplot(2,2,1)
%     plot(u_T(:,1),u_T(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,2)
%     plot(u_T(:,1),u_a(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,3)
%     plot(u_T(:,1),u_e(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
%     subplot(2,2,4)
%     plot(u_T(:,1),u_r(:,2),'color',[1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2),1-(j+Np/2)/(Np*3/2)],'linewidth',line_width)
     
    p0_rcx_r(j+1,1) = p0_rc(1);
    p0_rcy_r(j+1,1) = p0_rc(2);
    p0_rcz_r(j+1,1) = p0_rc(3);

    
    %N_dock = find(y_TILC_x<0.02 & y_TILC_x>-0.02);    %jr% Ӧ���ҵ�y_TILC_x��С����һ����׼ȷ,���ҽ����Ψһ�ģ�[Value,N_dock]=min(abs(y_TILC_x))
    [Value,N_dock]=min(abs(y_TILC_x));
    e_dock(j+1) = sqrt(y_TILC_y(N_dock)^2+y_TILC_z(N_dock)^2);
%     if e_dock(j+1) < 0.2
%         break;
%     end
end

figure(1)
subplot(2,2,1)
h = legend('$k=1$','$k=2$','$k=3$','Interpreter', 'latex', 'Location', 'best');
set(h,'Fontsize',font_size);
subplot(2,2,2)
h = legend('$k=1$','$k=2$','$k=3$','Interpreter', 'latex', 'Location', 'best');
set(h,'Fontsize',font_size);
subplot(2,2,3)
h = legend('$k=1$','$k=2$','$k=3$','Interpreter', 'latex', 'Location', 'best');
set(h,'Fontsize',font_size);
subplot(2,2,4)
h = legend('$k=1$','$k=2$','$k=3$','Interpreter', 'latex', 'Location', 'best');
set(h,'Fontsize',font_size);

% figure(2)
% subplot(2,2,1)
% h = legend('k=1','k=2','k=3','k=4','k=5');
% subplot(2,2,2)
% h = legend('k=1','k=2','k=3','k=4','k=5');
% subplot(2,2,3)
% h = legend('k=1','k=2','k=3','k=4','k=5');
% subplot(2,2,4)
% h = legend('k=1','k=2','k=3','k=4','k=5');


figure(3)
set(gcf,'color',[1 1 1])
plot3(Px_p(1:N_dock),-Py_p(1:N_dock),-Pz_p(1:N_dock),'k-','linewidth',line_width)
hold on 
plot3(Px_d(1:N_dock),-Py_d(1:N_dock),-Pz_d(1:N_dock),'k--','linewidth',line_width)
plot3(Px_d(N_dock)*ones(71,1),0.305*sin(0:0.1:7)'-Py_d(N_dock)*ones(71,1),0.305*cos(0:0.1:7)'-Pz_d(N_dock)*ones(71,1),'k:','linewidth',line_width)   %jr%  ��׶��ǰ��ΪԲ�ģ�0.305Ϊ�뾶��һ��Բ
hold off
grid on 
xlabel('x(m)','fontsize',font_size)
ylabel('y(m)','fontsize',font_size)
zlabel('z(m)','fontsize',font_size)
set(gca,'FontSize',font_size)
legend('׶��ǰ��','׶������','׶��ɡ��','Location', 'best')
axis equal

% figure(4)
% set(gcf,'color',[1 1 1])
% plot3(p0_rcx_r,-p0_rcy_r,-p0_rcz_r,'linewidth',line_width)
% hold on
% plot3(p0_rcx_r,-p0_rcy_r,-p0_rcz_r,'bo','linewidth',line_width)
% hold off
% grid on
% xlabel('x(m)','fontsize',font_size+5,'fontname','Times New Roman')
% ylabel('y(m)','fontsize',font_size+5,'fontname','Times New Roman')
% zlabel('z(m)','fontsize',font_size+5,'fontname','Times New Roman')
% set(gca,'FontSize',font_size)

% �������Ա�ͼ
e_dock_C3=e_dock;
save('e_dock_C3.mat','e_dock_C3')
load e_dock_C1
load e_dock_C2

figure(5)
set(gca,'FontSize',font_size)
xlabel('k','fontsize',font_size)
ylabel('$e_{\rm{dock}}(m)$','fontsize',font_size)
plot(e_dock_C3,'r-*','linewidth',line_width)
hold on
plot(e_dock_C1,'k--o','linewidth',line_width)
hold on
plot(e_dock_C2,'b:x','linewidth',line_width)
legend('Controller 1','Controller 2','Controller 3','Location', 'best')
hold off
grid on 

% %% ���ն˵���ѧϰ�����ս���洢��Ϊ��׼�������
% 
% er_x_ILC(:,1) = u_T(:,1);
% er_y_ILC(:,1) = u_T(:,1);
% er_z_ILC(:,1) = u_T(:,1);
% vr_ILC(:,1) = u_T(:,1);
% Pr_xr(:,1) = u_T(:,1);
% Pr_yr(:,1) = u_T(:,1);
% Pr_zr(:,1) = u_T(:,1);
% Pd_xr(:,1) = u_T(:,1);
% Pd_yr(:,1) = u_T(:,1);
% Pd_zr(:,1) = u_T(:,1);
% 
% er_x_ILC(:,2) = y_TILC_x;
% er_y_ILC(:,2) = y_TILC_y;
% er_z_ILC(:,2) = y_TILC_z;
% vr_ILC(:,2) = y_TILC_v;
% ur_T = u_T;
% ur_a = u_a;
% ur_e = u_e;
% Pr_xr(:,2) = Px_r;
% Pr_yr(:,2) = Py_r;
% Pr_zr(:,2) = Pz_r;
% Pd_xr(:,2) = Px_d;
% Pd_yr(:,2) = Py_d;
% Pd_zr(:,2) = Pz_d;
% save('er_ILC.mat','er_x_ILC','er_y_ILC','er_z_ILC','vr_ILC','ur_T','ur_a','ur_e','Pr_xr','Pr_yr','Pr_zr','Pd_xr','Pd_yr','Pd_zr')
% 
% %% for comparative plot
% Px_p1=Px_p(1:N_dock);
% Py_p1=Py_p(1:N_dock);
% Pz_p1=Pz_p(1:N_dock);
% Px_d1=Px_d(1:N_dock);
% Py_d1=Py_d(1:N_dock);
% Pz_d1=Pz_d(1:N_dock);
% save('Output_C1.mat','Px_p1','Py_p1','Pz_p1','Px_d1','Py_d1','Pz_d1')
