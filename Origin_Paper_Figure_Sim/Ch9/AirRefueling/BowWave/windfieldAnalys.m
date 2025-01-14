function [vx,vy,phi]=windfieldAnalys(x,y)
syms z;
ztk=0.0749998832206802;
phi1=int((0.056*z+0.024)*(y-ztk*z)/((x-z)^2+(y-ztk*z)^2),'z',0.07586201,3.2);
phi1=eval(phi1);
V=120;

phi=V*y-V*phi1;


vx=-int((0.056*z+0.024)*((x-z)^2-(y-ztk*z)^2)/((x-z)^2+(y-ztk*z)^2)^2,'z',0.07586201,3.2);
vx=eval(vx)*V;

vy=-int((0.056*z+0.024)*2*((x-z)*(y-ztk*z))/((x-z)^2+(y-ztk*z)^2)^2,'z',0.07586201,3.2);
vy=eval(vy)*V;


