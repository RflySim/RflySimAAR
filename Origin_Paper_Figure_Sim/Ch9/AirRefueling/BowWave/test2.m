[x,y]=meshgrid(-1.5:0.01:3,-1:0.02:2);
[vx,vy]=BowWaveFunc_v(x,y);
v=-10:0.5:10;
contour(x,y,vx-120,v);hold on;
colorbar;

figure
v1=0:2:30;
contour(x,y,vy,v1);hold on;
colorbar;