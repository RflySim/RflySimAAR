subplot(3,1,1)
plot(aa(:,7),aa(:,1))
hold on;
plot(aa(:,7),aa(:,4),'r')
axis([25 45 -5 10])
grid
title('xÖáÏò')

subplot(3,1,2)
plot(aa(:,7),-aa(:,3))
hold on;
plot(aa(:,7),-aa(:,6),'r')
axis([25 45 -6 -4])
grid
title('zÖáÏò')

subplot(3,1,3)
plot(aa(:,7),-aa(:,2))
hold on;
plot(aa(:,7),-aa(:,5),'r')
axis([25 45 -1 1])
grid
title('yÖáÏò')