[x,y]=meshgrid(-1.5:0.01:2.5,-1:0.02:1.5);
[vx,vy]=BowWaveFunc_v_paper(x,y);
v=100:2:140;
figure
contour(x,y,vx,v);hold on;
colorbar;
%axis equal;

figure
v1=-25:4:25;
contour(x,y,vy,v1);hold on;
colorbar;
%axis equal;