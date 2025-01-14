%% The corresponding Simulink is Bowwave2Drogue_v4_4TAES.slx %%
%close all
load F16_Real5_OpenLoopSuccessTest_Dai4
%分别运行NEWHDU.slx和NoHDU.slx也可以获取下列数据

% Paper3_dHoseLenNewHDU
% Paper3_dHoseLenNOHDU
% Paper3_DroguePostionNewHDU
% Paper3_DroguePostionNOHDU
% Paper3_HoseLengthNewHDU
% Paper3_HoseLengthNOHDU

index = 2001:3501;
dl = Paper3_dHoseLenNOHDU(index);
dl0 = Paper3_dHoseLenNewHDU(index);
l = Paper3_HoseLengthNOHDU(index);
l0 = Paper3_HoseLengthNewHDU(index);
pd = Paper3_DroguePostionNOHDU(index,3)-5;
pd0 = Paper3_DroguePostionNewHDU(index,3)-5;
pdy = Paper3_DroguePostionNOHDU(index,2);
pdy0 = Paper3_DroguePostionNewHDU(index,2);

t = (index-1)/100;

figure
set(gcf,'color',[1,1,1])

color1 = [0,146,35]/255;
color2 = [0,75,162]/255;
color3 = [1,0,0];
lstyle1 = '-';
lwidth1 = 2;
lstyle2 = '--';
lwidth2 = 2;
lstyle2_ = '^';
lwidth2_ = 4;
lstyle3 = '-';
lwidth3 = 2;
lstyle3_ = 'o';
lwidth3_ = 4;

% delta_t = 40;
% delta_t0 = 20;


subplot(4,1,1)
hold on
% grid on
box on
%axis([0,13,-inf,inf])
% plot(t,pos_pr(:,3)*0.3048,'linewidth',2,'color','b')
plot(t,l,lstyle1,'linewidth',lwidth1,'color',color1)
plot(t,l0,lstyle2,'linewidth',lwidth2,'color',color2)

subplot(4,1,2)
hold on
% grid on
box on
%axis([0,13,-inf,inf])
% plot(t,pos_pr(:,1)*0.3048,'linewidth',2,'color','b')
plot(t,dl,lstyle1,'linewidth',lwidth1,'color',color1)
plot(t,dl0,lstyle2,'linewidth',lwidth2,'color',color2)
% plot(t(1:delta_t:end),pos_dr1(1:delta_t:end,1)*0.3048,lstyle2_,'linewidth',lwidth2_,'color',color2)
% plot(t,pos_dr2(:,1)*0.3048,lstyle3,'linewidth',lwidth3,'color',color3)
% plot(t(1+delta_t0:delta_t:end),pos_dr2(1+delta_t0:delta_t:end,1)*0.3048,lstyle3_,'linewidth',lwidth3_,'color',color3)
%axis([4,12,-2,3]);
% xlabel('time/s','FontSize',12,'Fontname','Times New Roman')
% name = ['Longitudinal' 10 'position' 10 '(m,+fwd,Sim)'];  %char(10) 是 字元矩陣 與效果 \n 相同
%                                                     %直接用10也可以，记得前后加空格
% ylabel(name,'FontSize',12,'Fontname','Times New Roman')

% subplot(3,1,2)
% hold on
% grid on
% box on
% axis([0,13,-inf,inf])
% plot(t,pos_pr(:,2)*0.3048,'linewidth',2,'color','b')
% plot(t,pos_dr(:,2)*0.3048,lstyle1,'linewidth',lwidth1,'color',color1)
% plot(t,pos_dr1(:,2)*0.3048,lstyle2,'linewidth',lwidth2,'color',color2)
% plot(t(1:delta_t:end),pos_dr1(1:delta_t:end,2)*0.3048,lstyle2_,'linewidth',lwidth2_,'color',color2)
% plot(t,pos_dr2(:,2)*0.3048,lstyle3,'linewidth',lwidth3,'color',color3)
% plot(t(1+delta_t0:delta_t:end),pos_dr2(1+delta_t0:delta_t:end,2)*0.3048,lstyle3_,'linewidth',lwidth3_,'color',color3)
% xlabel('time/s','FontSize',12,'Fontname','Times New Roman')
% name = ['Lateral' 10 'position' 10 '(m,+right,Sim)'];  %char(10) 是 字元矩陣 與效果 \n 相同
%                                                     %直接用10也可以，记得前后加空格
% ylabel(name,'FontSize',12,'Fontname','Times New Roman')

% subplot(3,1,2)
% hold on
% % grid on
% box on
% %axis([0,13,-inf,inf])
% % plot(t,pos_pr(:,3)*0.3048,'linewidth',2,'color','b')
% plot(t,l,lstyle1,'linewidth',lwidth1,'color',color1)
% plot(t,l0,lstyle2,'linewidth',lwidth2,'color',color2)
% % plot(t(1:delta_t:end),pos_dr1(1:delta_t:end,3)*0.3048,lstyle2_,'linewidth',lwidth2_,'color',color2)
% % plot(t,pos_dr2(:,3)*0.3048,lstyle3,'linewidth',lwidth3,'color',color3)
% % plot(t(1+delta_t0:delta_t:end),pos_dr2(1+delta_t0:delta_t:end,3)*0.3048,lstyle3_,'linewidth',lwidth3_,'color',color3)
% %axis([4,12,-2,2]);
% % xlabel('time/s','FontSize',12,'Fontname','Times New Roman')
% % name = ['Vertical' 10 'position' 10 '(m,+up,Sim)'];  %char(10) 是 字元矩陣 與效果 \n 相同
% %                                                     %直接用10也可以，记得前后加空格
% % ylabel(name,'FontSize',12,'Fontname','Times New Roman')
% 
% % [0,153/256,74/256]

subplot(4,1,3)
hold on
% grid on
box on
%axis([0,13,-inf,inf])
% plot(t,pos_pr(:,3)*0.3048,'linewidth',2,'color','b')
plot(t,pd,lstyle1,'linewidth',lwidth1,'color',color1)
plot(t,pd0,lstyle2,'linewidth',lwidth2,'color',color2)


subplot(4,1,4)
hold on
% grid on
box on
%axis([0,13,-inf,inf])
% plot(t,pos_pr(:,3)*0.3048,'linewidth',2,'color','b')
plot(t,pdy,lstyle1,'linewidth',lwidth1,'color',color1)
plot(t,pdy0,lstyle2,'linewidth',lwidth2,'color',color2)


% figure
% hold on
% grid on
% plot(t,pos_g(:,1),'linewidth',3,'color','b')
% xlabel('time/s','FontSize',12,'Fontname','Times New Roman')
% ylabel('prcx-tk/m','FontSize',12,'Fontname','Times New Roman')