[x,y]=meshgrid(-1.5:0.01:3,-2:0.01:5);
z=BowWaveFunc1_paper1(x,y);
v=0:10:100;
contour(x,y,z,v);hold on;
colorbar;