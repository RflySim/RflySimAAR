function [ phi ] = BowWaveModel_addPoint_forpaper_use20_phi_cor(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.00218475410402450;0.00244651395194226;0.00573399624132927;0.00317606954688859;0.00921851938150908;0.00347287705184751;0.0103358589776281;0.0132801988660276;-0.0184686057704084;0.0967854143856357;-0.203150009815317;0.479347004378496;-0.927857864104681;1.76278542779437;-2.99717319675801;4.82360950185102;-7.09431378479349;9.62531562187360;-11.2944527437430;10.8392970240348;-7.29594197275583;2.60632779118896];
k_zt=0;
zt=0.07586201:0.1:2.2;
mm=length(zt);

V=120;
C1=zeros(1,mm);

[nr,nc]=size(x);
phi=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:mm
            C1(i)=y(row,cols)/((x(row,cols)-zt(i))^2+(y(row,cols)-k_zt*zt(i))^2);
        end  
        phi(row,cols)=V*y(row,cols)-C1*m*V;
        if y(row,cols)<0 && phi(row,cols)>=0
         phi(row,cols)=0;
        end
        
       if x(row,cols)>=0
          phi(row,cols)=phi(row,cols)/V;
       else
          phi(row,cols)=sqrt((phi(row,cols))^2+(V*x(row,cols))^2)/V;
       end
        
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

