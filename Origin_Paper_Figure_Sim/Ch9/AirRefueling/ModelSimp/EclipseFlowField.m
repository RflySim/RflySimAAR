[x,y]=meshgrid(-5:0.005:3,1:2);
a=6;
b=1;

[m,n]=size(x);
v=zeros(m,n);

Vt=120;
phi=zeros(m,n);

for i=1:m
    for j=1:n
        v(i,j)=2*Vt*(x(i,j)-a)*y(i,j)/a^2/(((x(i,j)-a)/a)^2+(y(i,j)/b)^2)^2;
        phi(i,j)=Vt*y(i,j)*(1-1/(((x(i,j)-a)/a)^2+(y(i,j)/b)^2));
        if ((x(i,j)-a)/a)^2+(y(i,j)/b)^2 <=1
            v(i,j)=0;
            phi(i,j)=0;
        else
            v(i,j)=v(i,j)*exp(-1.5*(((x(i,j)-a)/a)^2+(y(i,j)/b)^2-1));
        end
    end
end

v1=-30:2.5:30;
contour(x,y,v,v1);hold on;
colorbar;

v2=[-50,-40,-30,-20,-10,-0.1,0,0.1,10,20,30,40,50];
figure
contour(x,y,phi,v2);hold on;
colorbar;