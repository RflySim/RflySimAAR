clear length;
%Method3
x1=bowSinks(:,1);
y1=bowSinks(:,2);
z1=bowSinks(:,3);
x2=bowSinks(:,4);
y2=bowSinks(:,5);
z2=bowSinks(:,6);

t1=dockTime(end, 1);
t2=dockTime(end, 2);
t3=dockTime(end, 3);
t4=dockTime(end, 4);

t=1:length(x1);
t=(t-1)/100;
figure
subplot(3,1,1)
xx=x1(2500:3500);
plot(t,x1-mean(xx),'-','color',[0,0,0]/255,'LineWidth',1);
hold on;
plot(t,x2-mean(xx),'--','color',[0,0,0]/255,'LineWidth',1);
plot([t1,t1],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t2,t2],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t3,t3],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t4,t4],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([100,100],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
axis([40,260,-6,1])
legend('Probe','Drogue')


subplot(3,1,2)
yy=y1(2500:3500);
plot(t,y1-mean(yy),'-','color',[0,0,0]/255,'LineWidth',1);
hold on;
plot(t,y2-mean(yy),'--','color',[0,0,0]/255,'LineWidth',1);
plot([t1,t1],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t2,t2],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t3,t3],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t4,t4],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([100,100],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
axis([40,260,-0.5,1])

subplot(3,1,3)
zz=z1(2500:3500);
plot(t,-z1+mean(zz),'-','color',[0,0,0]/255,'LineWidth',1);
hold on;
plot(t,-z2+mean(zz),'--','color',[0,0,0]/255,'LineWidth',1);
plot([t1,t1],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t2,t2],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t3,t3],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([t4,t4],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
plot([100,100],[-10,10],'--','color',[0,0,0]/255,'LineWidth',1);
axis([40,260,-0.5,1])

for i=1:length(x1)
    rr(i)=sqrt((y1(i)-y2(i))^2+(z1(i)-z2(i))^2);

end

% subplot(4,1,4)
% 
% plot(t,rr,'color',[0,75,162]/255,'LineWidth',2);
% hold on;
% plot([50,70],[0.15,0.15],'--','color',[229,0,29]/255,'LineWidth',2);
% plot([69.16,69.16],[-10,10],'--','color',[232,119,44]/255,'LineWidth',2);
% axis([50,170,0,0.5])


% subplot(4,1,1)
% xx=x1(2500:3500);
% plot(t,x1-mean(xx));
% hold on;
% plot(t,x2-mean(xx),'r');
% plot([69.16,69.16],[-10,10],':k');
% axis([50,70,-5,1])
% legend('Probe','Drogue')
% 
% 
% subplot(4,1,2)
% yy=y1(2500:3500);
% plot(t,y1-mean(yy));
% hold on;
% plot(t,y2-mean(yy),'r');
% plot([69.16,69.16],[-10,10],':k');
% axis([50,70,-0.5,0.8])
% 
% subplot(4,1,3)
% zz=z1(2500:3500);
% plot(t,-z1+mean(zz));
% hold on;
% plot(t,-z2+mean(zz),'r');
% plot([69.16,69.16],[-10,10],':k');
% axis([50,70,-0.5,1])
% 
% for i=1:length(x1)
%     rr(i)=sqrt((y1(i)-y2(i))^2+(z1(i)-z2(i))^2);
% end
% 
% subplot(4,1,4)
% 
% plot(t,rr);
% hold on;
% plot([50,70],[0,0],':g');
% plot([69.16,69.16],[-10,10],':k');
% axis([50,70,-0.5,0.5])
% 
% 
% 
% xd=[];
% for i=1:20000
%     if (x1(i)-x2(i))<0.005&&(x1(i)-x2(i))>0
%         xd=[xd,i];
%     end
% end
