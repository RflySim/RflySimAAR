function [ phi ] = BowWaveFunc1_useSourceM(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.0941300407412281;0.0532383805720434;0.0186898433096202;0.0268496907661979;0.00180292507416392;-0.000200572103793782;-0.00462335069015226;-0.00916495790326414;-0.0146179300463528;-0.0200593937329390;-0.0201749410353472;-0.0261892995623836;-0.0316166578709344;-0.0392289600392001;-0.0360467896430784;-0.0321785564149143;-0.0442606772388813;-0.0469380344176477;-0.0803770745672276;-0.0934751918782205;-0.0680203663056237;-0.608471276593771];
k_zt=0.0749998832206802;
zt=0.07586201:0.1:2.2;
mm=length(zt);

V=100;
C1=zeros(1,mm);

[nr,nc]=size(x);
phi=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:mm
              tt=atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i)));
%               if (x(row,cols)-zt(i))<0
%                   tt=tt+pi;
%               end
      
             C1(i)=tt;
        end  
        phi(row,cols)=V*y(row,cols)-C1*m*V;
        %phi(row,cols)=C1*m;
        
        if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
            phi(row,cols)=0;
        end
        
    end
end

end

