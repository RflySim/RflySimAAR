%Method3
x1=bowSinks(:,1);
y1=bowSinks(:,2);
z1=bowSinks(:,3);
x2=bowSinks(:,4);
y2=bowSinks(:,5);
z2=bowSinks(:,6);

t=1:length(x1);
t=(t-1)/100;

subplot(4,1,1)
xx=x1(2500:3500);
plot(t,x1-mean(xx));
hold on;
plot(t,x2-mean(xx),'r');
plot([69.23,69.23],[-10,10],':k');
axis([45,70,-5,1])
legend('Probe','Drogue')


subplot(4,1,2)
yy=y1(2500:3500);
plot(t,y1-mean(yy));
hold on;
plot(t,y2-mean(yy),'r');
plot([69.23,69.23],[-10,10],':k');
axis([45,70,-0.5,0.8])

subplot(4,1,3)
zz=z1(2500:3500);
plot(t,-z1+mean(zz));
hold on;
plot(t,-z2+mean(zz),'r');
plot([69.23,69.23],[-10,10],':k');
axis([45,70,-0.5,1])

for i=1:length(x1)
    rr(i)=sqrt((y1(i)-y2(i))^2+(z1(i)-z2(i))^2);
end

subplot(4,1,4)

plot(t,rr);
hold on;
plot([45,70],[0,0],':g');
plot([69.23,69.23],[-10,10],':k');
axis([45,70,-0.5,1])



xd=[];
for i=1:20000
    if (x1(i)-x2(i))<0.005&&(x1(i)-x2(i))>0
        xd=[xd,i];
    end
end
