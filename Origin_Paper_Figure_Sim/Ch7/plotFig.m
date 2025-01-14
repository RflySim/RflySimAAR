figure(1)
set(gcf,'color',[1 1 1])
plot(in_mass.time,in_mass.signals.values(:,1),'b-','linewidth',1.5);
hold on
grid on
plot(va_mass.time,va_mass.signals.values(:,1),'r--','linewidth',1.5);
h = legend('Constant mass','Varying mass');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')

figure(2)
set(gcf,'color',[1 1 1])
plot(in_mass.time,in_mass.signals.values(:,2),'b-','linewidth',1.5);
hold on
grid on
plot(va_mass.time,va_mass.signals.values(:,2),'r--','linewidth',1.5);
h = legend('Constant mass','Varying mass');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')

figure(3)
set(gcf,'color',[1 1 1])
plot(in_mass.time,in_mass.signals.values(:,3),'b-','linewidth',1.5);
hold on
grid on
plot(va_mass.time,va_mass.signals.values(:,3),'r--','linewidth',1.5);
h = legend('Constant mass','Varying mass');
set(h,'Fontsize',14,'fontname','TimesNewRoman');
set(gca,'FontSize',14,'fontname','TimesNewRoman')