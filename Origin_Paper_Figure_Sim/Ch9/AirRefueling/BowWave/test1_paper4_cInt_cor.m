[x1,y1]=meshgrid(-1:0.05:2.2,-0.01:0.01:1);

V=120;

[nr,nc]=size(x1);
z1=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
          z1(row,cols)=windfieldAnalys2_cor(x1(row,cols),y1(row,cols));
    end
end


%z=BowWaveFunc1_paper3(x,y);
v=0:0.05:0.5;
figure;
contour(x1,y1,z1,v);hold on;
%axis equal;
colorbar;
