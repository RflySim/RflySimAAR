x1=bowSinks(:,1);
y1=bowSinks(:,2);
z1=bowSinks(:,3);
x2=bowSinks(:,4);
y2=bowSinks(:,5);
z2=bowSinks(:,6);
figure

t=1:length(x1);
t=(t-1)/100;

subplot(3,1,1)
xx=x1(2500:3500);
plot(t,x1-mean(xx));
hold on;
plot(t,x2-mean(xx),'r');
grid
axis([100,120,-5,1])

subplot(3,1,2)
yy=y1(2500:3500);
plot(t,y1);
hold on;
plot(t,y2,'r');
grid
axis([100,120,-0.5,0.6])

subplot(3,1,3)
zz=z1(2500:3500);
plot(t,-z1+mean(zz));
hold on;
plot(t,-z2+mean(zz),'r');
grid
axis([100,120,-0.5,0.5])

% xd=[];
% for i=1:20000
%     if (x1(i)-x2(i))<0.005&&(x1(i)-x2(i))>0
%         xd=[xd,i];
%     end
% end
