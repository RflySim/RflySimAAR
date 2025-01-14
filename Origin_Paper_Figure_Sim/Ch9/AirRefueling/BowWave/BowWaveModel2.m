PointData=[-4.2490 -0.8599;
    -4.230607 -0.8277521;
    -4.1745229 -0.79347879;
    -4.0552773 -0.7479157;
    -3.8535058 -0.69086123;
    -3.6240239 -0.63797694;
    -3.328908 -0.57846528;
    -3.0118942 -0.52067065;
    -2.663825 -0.46204835;
    -2.115184 -0.37608668];
PointData(:,1)=PointData(:,1)-(-4.2490);
PointData(:,2)=PointData(:,2)-(-0.8599);

nl1=length(PointData(:,1));
PointX=PointData(2:nl1,1);
PointY=PointData(2:nl1,2);

PointA=[-2.10921 -0.699441]'-[-4.2490 -0.8599]';
k_zita=PointA(2)/PointA(1);

dev=PointData(nl1,1)/nl1;
zita=dev:dev:PointData(nl1,1);

C=zeros(nl1-1,nl1-1);
for i=1:nl1-1
   for j=1:nl1-1
      C(i,j)= PointY(i)/((PointX(i)-zita(j))^2+(PointY(i)-k_zita*zita(j))^2);
   end
end

m=C^-1*PointY;
plot(m)