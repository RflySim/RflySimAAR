figure(1)
set(gcf,'color',[1 1 1])
plot(actual_trajectory.time,actual_trajectory.signals.values(:,1),'b--','linewidth',2);
hold on
grid on
plot(reference_trajectory.time,reference_trajectory.signals.values(:,1),'r-','linewidth',2);
h = legend('Actual trajectory','Reference trajectory');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')

figure(2)
set(gcf,'color',[1 1 1])
plot(actual_trajectory.time,actual_trajectory.signals.values(:,2),'b--','linewidth',2);
hold on
grid on
plot(reference_trajectory.time,reference_trajectory.signals.values(:,2),'r-','linewidth',2);
h = legend('Actual trajectory','Reference trajectory');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')

figure(3)
set(gcf,'color',[1 1 1])
plot(actual_trajectory.time,actual_trajectory.signals.values(:,3),'b--','linewidth',2);
hold on
grid on
plot(reference_trajectory.time,reference_trajectory.signals.values(:,3),'r-','linewidth',2);
h = legend('Actual trajectory','Reference trajectory');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')