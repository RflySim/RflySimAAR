%Method3
x1=bowSinks(:,1);
y1=bowSinks(:,2);
z1=bowSinks(:,3);
x2=bowSinks(:,4);
y2=bowSinks(:,5);
z2=bowSinks(:,6);

t=1:length(x1);
t=(t-1)/100;
figure
subplot(4,1,1)
xx=x1(2500:3500);
plot(t,x1-mean(xx),'--','color',[0,146,35]/255,'LineWidth',2);
hold on;
plot(t,x2-mean(xx),'color',[0,75,162]/255,'LineWidth',2);
plot([69.225,69.225],[-10,10],'--','color',[232,119,44]/255,'LineWidth',2);
axis([50,80,-8,1])
legend('Drogue','Probe')


subplot(4,1,2)
yy=y1(2500:3500);
plot(t,y1-mean(yy),'--','color',[0,146,35]/255,'LineWidth',2);
hold on;
plot(t,y2-mean(yy),'color',[0,75,162]/255,'LineWidth',2);
plot([69.225,69.225],[-10,10],'--','color',[232,119,44]/255,'LineWidth',2);
axis([50,70,-0.5,1])

subplot(4,1,3)
zz=z1(2500:3500);
plot(t,-z1+mean(zz),'--','color',[0,146,35]/255,'LineWidth',2);
hold on;
plot(t,-z2+mean(zz),'color',[0,75,162]/255,'LineWidth',2);
plot([69.225,69.225],[-10,10],'--','color',[232,119,44]/255,'LineWidth',2);
axis([50,70,-0.5,1])

for i=1:length(x1)
    rr(i)=sqrt((y1(i)-y2(i))^2+(z1(i)-z2(i))^2);
end

subplot(4,1,4)

plot(t,rr,'color',[0,75,162]/255,'LineWidth',2);
hold on;
plot([50,70],[0.15,0.15],'--','color',[229,0,29]/255,'LineWidth',2);
plot([69.225,69.225],[-10,10],'--','color',[232,119,44]/255,'LineWidth',2);
axis([50,70,0,0.5])
%legend('Radinal distance','Security line')


% 
% xd=[];
% for i=1:20000
%     if (x1(i)-x2(i))<0.005&&(x1(i)-x2(i))>0
%         xd=[xd,i];
%     end
% end
