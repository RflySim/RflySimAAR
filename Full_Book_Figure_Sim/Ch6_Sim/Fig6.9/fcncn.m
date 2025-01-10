function yy = fcncn(u)
%#codegen
yy=zeros(3,1);

Iin=u;

[L,N]=bwlabel(Iin,8);

%[L,N]=[u(1),u(2)];
S=zeros(N,2);
 for k=1:N
     [r,c]=find(L == k);
     S(k,1)=mean(r);
     S(k,2)=mean(c);
     
 end
%plot(S(:,1),S(:,2),'+')
% dx(:,1)=S(:,1)-mean(S(:,1));
% dy(:,1)=S(:,2)-mean(S(:,2));

dX=S(:,1);
dY=S(:,2);

m=[dX dY ones(size(dX))]\-(dX.^2+dY.^2);
cX=-0.5*m(1);
cY=-0.5*m(2);
cR=sqrt((m(1)^2+m(2)^2)/4-m(3));

% alpha=0:pi/50:2*pi;
% x=cR*cos(alpha)+cX;
% y=cR*sin(alpha)+cY;


yy = [cX;cY;cR];