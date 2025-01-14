[x,y]=meshgrid(-1.5:0.01:3,-0.5:0.01:0.5);
z=BowWaveFunc(x,y);
v=0:1:10;
contour(x,y,z,v);hold on;
colorbar;
%axis('equal')
axis([-1.5 3 -0.5 0.5])
%axis equal