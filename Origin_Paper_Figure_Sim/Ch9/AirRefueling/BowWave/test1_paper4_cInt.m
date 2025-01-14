[x1,y1]=meshgrid(-1.5:0.05:2.2,-0.1:0.01:0.8);

V=120;

[nr,nc]=size(x1);
z1=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
          z1(row,cols)=windfieldAnalys2(x1(row,cols),y1(row,cols));
    end
end


%z=BowWaveFunc1_paper3(x,y);
v=0.1:1:10;
figure;
contour(x1,y1,z1,v);hold on;
%axis equal;
colorbar;
