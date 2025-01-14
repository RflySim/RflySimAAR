plot(t,y_out1(:,1),'r');
hold on
plot(t,y_out1(:,2),'r:');
plot(t,y_out(:,3),'k:');
plot(t,y_out(:,4),'k');
plot(t,y_out(:,5),'b');
plot(t,y_out(:,6),'b:');
legend('h','xd','\theta','v','\alpha','q');