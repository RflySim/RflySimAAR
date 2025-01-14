
figure(1)
simCom1=simCom;
simCom1(:,3)=-simCom1(:,3);
% simCom1(:,1)=simCom1(:,1)-7;
%simCom(:,2)=-simCom(:,2);
plot(simCom1,'k')
hold on
plot(simVRMes,'--r')

figure(2)
errorx=simCom1(:,1)-simVRMes(:,1);
errory=simCom1(:,2)-simVRMes(:,2);
errorz=simCom1(:,3)-simVRMes(:,3);
t=0:0.02:14;
plot(t,errorx,'r');hold on
plot(t,errory,'g');hold on

plot(t,errorz,'b');hold on
% figure(2)
% sim=simVRMes;
% sim(:,1)=kalman1(simVRMes(:,1));
% sim(:,2)=kalman1(simVRMes(:,2));
% sim(:,3)=kalman1(simVRMes(:,3));
% plot(simCom1,'k')
% hold on
% plot(sim,'--r')
% function Xkf=kalman1(A)
% N=length(A);
% X=zeros(1,N);  
% Xkf=zeros(1,N);
% Z=zeros(1,N);
% P=zeros(1,N); 
% Z=A;
% P(1)=1;
% Xkf(1)=Z(1);
% Q=10;
% R=10;
% W=sqrt(Q)*randn(1,N);
% V=sqrt(R)*randn(1,N);
% F=1;
% G=1;
% H=1;
% I=eye(1); 
% for k=2:N
%     X_pre=F*Xkf(k-1);           
%     P_pre=F*P(k-1)*F'+Q;        
%     Kg=P_pre*inv(H*P_pre*H'+R); 
%     e=Z(k)-H*X_pre;            
%     Xkf(k)=X_pre+Kg*e;         
%     P(k)=(I-Kg*H)*P_pre;
% end
% end