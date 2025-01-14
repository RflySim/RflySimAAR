u=[-35.5,8.5,8]';

c_lat=3.19;
c_lon=3.578;

u1 = u+[0 ,c_lat ,0]';
u2 = u+[0 ,-c_lat, 0]';

yy1 = TankerVortexWindField(u1);
yy2 = TankerVortexWindField(u2);

yp = (yy1(3) - yy2(3))/2/c_lat;

u3=u+[c_lon, 0,0]';
u4=u+[-c_lon ,0,0]';
yy3 = TankerVortexWindField(u3);
yy4 = TankerVortexWindField(u4);

yq = (yy3(3) - yy4(3))/2/c_lon;

yr = 0;

y_uvw = TankerVortexWindField(u);
y = [y_uvw;yp;yq;yr]