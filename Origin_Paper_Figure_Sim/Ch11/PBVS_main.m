clear,clc;

Ts = 0.02;
Tend = 70;  % 仿真结束的时刻
Nend = Tend/Ts;
t=1:Nend+1;

% DeltaP_x=-1:0.5:1; % x方向位置测量误差
% DeltaP_y=-1:0.5:1; % y方向位置测量误差
DeltaP_z=-1:0.5:1; % z方向位置测量误差

    Nt = 5;  %对接次数
    Nr = 0;   %成功次数
    Nd = 0;   %失败次数

    for j = 1:Nt
        disp(j)

        DeltaP=[0,0,DeltaP_z(j)];

        sim("AirRefueling_Platform_PBVS.slx");

        N_dock = find(P_dr_pr(:,1)<0.02 & P_dr_pr(:,1)>-0.02);
        if isempty(N_dock(:))==1
            Nd = Nd+1;
        else
            e_dock = sqrt(P_dr_pr(N_dock(1),2)^2+P_dr_pr(N_dock(1),3)^2);
            if e_dock < 0.3
                Nr = Nr+1;
            else
                Nd = Nd+1;
            end
        end
    end

Percent = Nr/Nt;


font_size = 24;
line_width = 1.2;

figure(1)
set(gcf,'color',[1 1 1])
hold on
grid on
plot(t,P_dr_pr(:,1),'linewidth',line_width)
plot(t,P_dr_pr(:,2),'linewidth',line_width)
plot(t,P_dr_pr(:,3),'linewidth',line_width)
xlabel('t(s)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('relative distance(m)','fontsize',font_size+5,'fontname','Times New Roman')
legend('relative distance along x axis','relative distance along y axis','relative distance along z axis')
set(gca,'FontSize',font_size)

figure(2)
set(gcf,'color',[1 1 1])
grid on
plot3(P_dr_pr(:,1),P_dr_pr(:,2),P_dr_pr(:,3),'linewidth',line_width)
xlabel('x(m)','fontsize',font_size+5,'fontname','Times New Roman')
ylabel('y(m)','fontsize',font_size+5,'fontname','Times New Roman')
zlabel('z(m)','fontsize',font_size+5,'fontname','Times New Roman')
set(gca,'FontSize',font_size)




