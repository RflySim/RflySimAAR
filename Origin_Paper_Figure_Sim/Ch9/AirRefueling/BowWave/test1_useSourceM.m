[x,y]=meshgrid(-1.5:0.01:3,-0.5:0.01:0.5);
z=BowWaveFunc1_useSourceM(x,y);
v=-5:1:10;
contour(x,y,z,v);hold on;
colorbar;