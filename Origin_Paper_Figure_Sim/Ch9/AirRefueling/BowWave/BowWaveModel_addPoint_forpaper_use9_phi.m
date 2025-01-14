function [ phi ] = BowWaveModel_addPoint_forpaper_use9_phi(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.00408584105474723;0.0136080919521764;0.0162777264961093;0.0214097483963122;0.0321011043789211;0.0100769218403139;0.0938261384539696;-0.0850134971267182;0.231477396553004];

k_zt=0;
zt=0.1:0.24:2.2;
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
        
        
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

