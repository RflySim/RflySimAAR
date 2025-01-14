[x,y]=meshgrid(-1.5:0.01:3.5,-1:0.02:1.5);
[vx,vy]=BowWaveFunc_v_paper3(x,y);
v=80:4:160;
figure
contour(x,y,vx,v);hold on;
colorbar;
%axis equal;

figure
v1=-25:2:25;
contour(x,y,vy,v1);hold on;
colorbar;
%axis equal;