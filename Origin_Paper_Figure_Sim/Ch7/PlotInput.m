T = actual_trajectory.time;

figure
set (gcf,'Position',[400,100,800,800], 'color','w')
subplot(1,4,1)
plot(T,Thrust(:,1),'b','linewidth',1.5)
xlabel('Time (s)')
ylabel('\delta_t (lbs)')
grid on

subplot(1,4,2)
plot(T,ActuatorAng(:,1),'r','linewidth',1.5)
xlabel('Time (s)')
ylabel('\delta_e (deg)')
grid on

subplot(1,4,3)
plot(T,ActuatorAng(:,2),'g','linewidth',1.5)
xlabel('Time (s)')
ylabel('\delta_a (deg)')
grid on

subplot(1,4,4)
plot(T,ActuatorAng(:,3),'b','linewidth',1.5)
xlabel('Time (s)')
ylabel('\delta_r (deg)')
grid on