function [ phi ] = BowWaveFunc1_paper4(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.00179733
0.0030959
0.003702249
0.004842862
0.004981955
0.005855091
0.006353769
0.006468435
0.007641252
0.007412809
0.008929336
0.008929336
0.009929336
0.009929336
0.010929336
0.010929336
0.011929336
0.011929336
0.012929336
0.012929336
0.013129336
0.013229336
0.013429336
0.013629336
0.014829336
0.015029336
0.016229336
0.017429336
0.018629336
0.019829336
0.0200029336
0.021229336
];

k_zt=0.0749998832206802;
zt=0.07586201:0.1:3.2;
zt_k=k_zt*zt;
mm=length(zt);
% zt(mm+1)=2.2812748;
% zt_k(mm+1)=0.50234;
% zt(mm+2)=2.512748;
% zt_k(mm+2)=0.50234;
% zt(mm+3)=3.012748;
% zt_k(mm+3)=0.50234;
% zt(mm+4)=3.212748;
% zt_k(mm+4)=0.55234;
% m(mm+1)=0.04;
% m(mm+2)=0.05;
% m(mm+3)=0.05;
% m(mm+4)=0.06;
% 
% mm=mm+4;

V=120;
C1=zeros(1,mm);

[nr,nc]=size(x);
phi=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:mm
            C1(i)=(y(row,cols)-zt_k(i))/((x(row,cols)-zt(i))^2+(y(row,cols)-zt_k(i))^2);
        end  
        phi(row,cols)=V*y(row,cols)-C1*m*V;
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

