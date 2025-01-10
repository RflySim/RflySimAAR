T = actual_trajectory.time;

figure
set (gcf,'Position',[400,100,800,800], 'color','w')
subplot(3,3,1)
plot(T,State12(:,10),'b','linewidth',1.5)
xlabel('Time (s)')
ylabel('p (rad/s)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,2)
plot(T,State12(:,11),'r','linewidth',1.5)
xlabel('Time (s)')
ylabel('q (rad/s)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,3)
plot(T,State12(:,12),'g','linewidth',1.5)
xlabel('Time (s)')
ylabel('r (rad/s)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,4)
plot(T,State12(:,4),'b','linewidth',1.5)
xlabel('Time (s)')
ylabel('\phi (rad)')
% xlim([min(t) max(t)])
grid on
 
subplot(3,3,5)
plot(T,State12(:,5),'r','linewidth',1.5)
xlabel('Time (s)')
ylabel('\theta (rad)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,6)
plot(T,State12(:,6),'g','linewidth',1.5)
xlabel('Time (s)')
ylabel('\psi (rad)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,7)
plot(T,State12(:,7),'b','linewidth',1.5)
xlabel('Time (s)')
ylabel('V (ft/s)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,8)
plot(T,State12(:,8),'r','linewidth',1.5)
xlabel('Time (s)')
ylabel('\alpha (rad)')
% xlim([min(t) max(t)])
grid on

subplot(3,3,9)
plot(T,State12(:,9),'g','linewidth',1.5)
xlabel('Time (s)')
ylabel('\beta (rad)')
% xlim([min(t) max(t)])
grid on

