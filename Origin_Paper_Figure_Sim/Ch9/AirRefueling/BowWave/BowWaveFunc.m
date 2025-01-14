function [ phi ] = BowWaveFunc(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.000211657645657116;0.00161659314264688;0.00504712437001751;0.00974789497450676;0.0154883351255213;0.0223275897120843;0.0278522405284552;0.0433472296581069;0.0887559256809001];

k_zt=0.0749998832206802;
zt=[0.0183929999999997;0.0744770999999993;0.193722699999999;0.395494199999999;0.624976100000000;0.920092000000000;1.23710580000000;1.58517500000000;2.13381600000000];
V=100;
C1=zeros(1,9);

[nr,nc]=size(x);
phi=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:9
            C1(i)=y(row,cols)/((x(row,cols)-zt(i))^2+(y(row,cols)-k_zt*zt(i))^2);
        end  
        phi(row,cols)=V*y(row,cols)-C1*m*V;
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

