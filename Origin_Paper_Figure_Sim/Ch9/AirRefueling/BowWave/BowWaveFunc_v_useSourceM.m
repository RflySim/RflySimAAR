function [ vx,vy ] = BowWaveFunc_v_useSourceM(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.00179733009245565;0.00309589969062575;0.00370224859051461;0.00484286161176734;0.00498195515024255;0.00585509096135794;0.00635376868038751;0.00646843476334938;0.00764125170322964;0.00741280862826003;0.00792933570093085;0.00941812295565618;0.00673884505583494;0.0139083536266520;0.00166691982660244;0.0237234234049040;-0.0121134250356596;0.0508977166921980;-0.0568887446685529;0.122667803294485;-0.136845774358203;0.142408310880833];
k_zt=0.0749998832206802;
zt=0.07586201:0.1:2.2;
mm=length(zt);

V=120;
C1vx=zeros(1,mm);
C1vy=zeros(1,mm);

[nr,nc]=size(x);
vx=zeros(nr,nc);
vy=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:mm
            C1vx(i)=((x(row,cols)-zt(i))^2-(y(row,cols)-k_zt*zt(i))^2)/((x(row,cols)-zt(i))^2+(y(row,cols)-k_zt*zt(i))^2)^2;
            C1vy(i)=2*(x(row,cols)-zt(i))*(y(row,cols)-k_zt*zt(i))/((x(row,cols)-zt(i))^2+(y(row,cols)-k_zt*zt(i))^2)^2;
        end  
        vx(row,cols)=V+C1vx*m*V;
        vy(row,cols)=-C1vy*m*V;
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

