
simCom1=simCom;
simCom1(:,3)=-simCom1(:,3);
simCom1(:,1)=simCom1(:,1)-7;
%simCom(:,2)=-simCom(:,2);

plot(simCom1)
hold on

plot(simVRMes,':')