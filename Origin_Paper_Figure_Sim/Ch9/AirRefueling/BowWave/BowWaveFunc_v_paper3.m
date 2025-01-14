function [ vx,vy ] = BowWaveFunc_v_paper3(x,y )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
m=[0.00336491972228728;0.00366710161864603;0.00554889177126323;0.00588761898721337;0.00725977852357990;0.00748989662919857;0.00898293392955319;0.00871785600484608;0.0107059630697635;0.0101289104418734;0.0116721042341978;0.0122183771054350;0.0119256706493999;0.0155626068582273;0.00991469982375837;0.0226741471613134;0.000223482401912722;0.0482476491636743;-0.0472965194303980;0.137827719312441;-0.163289861011145;0.192429877377768];


k_zt=0.0749998832206802;
zt=0.07586201:0.1:2.2;
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
C1vx=zeros(1,mm);
C1vy=zeros(1,mm);

[nr,nc]=size(x);
vx=zeros(nr,nc);
vy=zeros(nr,nc);
for row=1:nr
    for cols=1:nc
        
        for i=1:mm
            C1vx(i)=((x(row,cols)-zt(i))^2-(y(row,cols)-zt_k(i))^2)/((x(row,cols)-zt(i))^2+(y(row,cols)-zt_k(i))^2)^2;
            C1vy(i)=2*(x(row,cols)-zt(i))*(y(row,cols)-zt_k(i))/((x(row,cols)-zt(i))^2+(y(row,cols)-zt_k(i))^2)^2;
        end  
        vx(row,cols)=V-C1vx*m*V*0.5;
        vy(row,cols)=-C1vy*m*V;
        %phi(row,cols)=C1*m;
        
%         if abs(atan((y(row,cols)-k_zt*zt(i))/(x(row,cols)-zt(i))))<0.152
%             phi(row,cols)=0;
%         end
        
    end
end

end

