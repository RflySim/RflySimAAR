T=t;
T(1,:)=[];
Z_cd=z_cd;
Z_cd(1,:)=[];
e_imag=E_imag;
e_imag(1,:)=[];

font_size = 20;
%%x,y实时位置误差
figure(1)
set(gcf,'color',[1 1 1])
hold on
grid on

plot(t,d_pr_dr(:,2),'k','LineStyle', '-', 'LineWidth', 1);
plot(t,d_pr_dr(:,3),'k','LineStyle', '--', 'LineWidth', 1);


xlabel('Time (s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('Relative distance (m)','fontsize',font_size,'fontname','Times New Roman')
axis([0 30 -5 5] )
legend('Relative distance along x axis','Relative distance along y axis','Location','southeast')
set(gca,'FontSize',font_size)


%%深度z_d实时位置误差
figure(2)
set(gcf,'color',[1 1 1])
hold on
grid on

plot(t,d_pr_dr(:,1),'k','LineStyle', '-', 'LineWidth', 1);


xlabel('Time (s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('Relative distance (m)','fontsize',font_size,'fontname','Times New Roman')
axis([0 30 -10 1])
legend('Relative distance along z axis','Location','southeast')
set(gca,'FontSize',font_size)

%%z方向图像误差
figure(3)
set(gcf,'color',[1 1 1])
plot(T,Z_cd(:,2),'k','LineStyle', '-', 'LineWidth', 1);
grid on 

xlabel('Time (s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('Image tracking error (ft)','fontsize',font_size,'fontname','Times New Roman')
axis([0 30 -1 10])
legend('Image tracking error in z axis')
set(gca,'FontSize',font_size)


%%xy方向图像误差ex,ey
figure(4)
set(gcf,'color',[1 1 1])
hold on
grid on

plot(T,e_imag(:,1),'k','LineStyle', '-', 'LineWidth', 1)
plot(T,e_imag(:,2),'k','LineStyle', '--', 'LineWidth', 1)
xlabel('Time (s)','fontsize',font_size,'fontname','Times New Roman')
ylabel('Image tracking error (ft)','fontsize',font_size,'fontname','Times New Roman')

legend('Image tracking error in x axis','Image tracking error in y axis','Location','southeast')
axis([0 30 -200 50])
set(gca,'FontSize',font_size)

%%实时位置误差（x,y,z）
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