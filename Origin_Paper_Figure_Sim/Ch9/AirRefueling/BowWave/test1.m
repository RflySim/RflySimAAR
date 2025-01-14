[x,y]=meshgrid(-1.5:0.01:3,-2:0.01:2);
z=BowWaveFunc1(x,y);
v=0:10:100;
contour(x,y,z,v);hold on;
colorbar;