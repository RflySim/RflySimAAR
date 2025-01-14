%% �����Ŷ����ٶ� V_wind �ͽ��ٶ� W_wind �������ٻ�ͼ
%% ����
clear uvw pqr m
step = 400; % ��������
m = floor(size(V_wind.time,1)/step);
pqr(m,3) = 0;
uvw(m,3) = 0;
for i=1:m
uvw(i,:) = V_wind.signals.values(step*i,:);
pqr(i,:) = W_wind.signals.values(step*i,:);
end
uvw(:,4) = 0;
pqr(:,4) = 0;
for i=1:m
uvw(i,4) = V_wind.time(step*i);
pqr(i,4) = W_wind.time(step*i);
end

%% ��ͼ
figure(1)
set(gcf,'color',[1 1 1])
plot(uvw(:,4),uvw(:,1),'k-','linewidth',1.5)
hold on
grid on
plot(uvw(:,4),uvw(:,2),'r--','linewidth',1.5)
hold on
plot(uvw(:,4),uvw(:,3),'b-.','linewidth',1.5)
h = legend('Vx','Vy','Vz');
set(h,'Fontsize',14);
set(gca,'FontSize',14)

figure(2)
set(gcf,'color',[1 1 1])
plot(pqr(:,4),pqr(:,1),'k-','linewidth',1.5)
hold on
grid on
plot(pqr(:,4),pqr(:,2),'r--','linewidth',1.5)
hold on
plot(pqr(:,4),pqr(:,3),'b-.','linewidth',1.5)
h = legend('Wp','Wq','Wr');
set(h,'Fontsize',14);
set(gca,'FontSize',14)