[x,y]=meshgrid(-1.5:0.01:3,-2:0.01:2);
z=BowWaveFunc1_paper3(x,y);
v=-1:10:100;
contour(x,y,z,v);hold on;
colorbar;