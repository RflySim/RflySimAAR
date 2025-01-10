function y = TankerVortexWindField(PosReceiver)
%#codegen


airDensity1 = 0.58950;               %��߶ȱ�����
airSpeed1 = 120;

wingSpan1 = 40;
tankerWeight1 = 80000;               %KC-135���������146000kg��ȡ��ֵ
gravity1 = 9.79434;                  %γ��43.3���߶�7000��������

%������Flight Data Analysis and Simulation of Wind Effects During Aerial Refueling
vortexStrength = tankerWeight1*gravity1 / (airDensity1*airSpeed1*pi/4*wingSpan1);

%���¶���Ϊ�Զ������������ϵ

%���λ�ã��Ի�������Ϊԭ��
wingTipLeftPos = [0 -20 0]';
wingTipRightPos = [0 20 0]';

%β�������λ�ã�ͬ������ϵ
tailTipLeftPos = [-12.44 -6.515 -1.27]';
tailTipRightPos = [-12.44 6.515 -1.27]';

%���ͻ����ģ��������ο��㣩�ڱ�����ϵ��λ��
tankerMassPos = [0 0 0]';

%����Ϊ���ڼ��ͻ���������ϵλ�ã�ת��Ϊ�ڱ��Զ�������ϵλ��
receiverPos =PosReceiver + tankerMassPos;

%���(L)�����������
rVorL = sqrt((receiverPos(2)-wingTipLeftPos(2))^2 + (receiverPos(3)-wingTipLeftPos(3))^2);      %�����߾���(����������)
tVorL = -receiverPos(1)/airSpeed1;                                                               %��ʱ�䳣�� 
TVorL = vortexStrength;                                                                         %��ǿ��
vVorL = 0.06*TVorL;                                                                             %��ճ��
rVorCoreL = 2.24*sqrt(abs(vVorL*tVorL));                                                             %�к�
%rVorCoreL = 2.24*sqrt(vVorL*tVorL)

WVorL = TVorL*rVorL/(2*pi*(rVorL^2+rVorCoreL^2))*(1-exp(-rVorL^2/(4*vVorL*tVorL)));             %�յ��糡��С   
thetaVorL = atan((receiverPos(3)-wingTipLeftPos(3))/(receiverPos(2)-wingTipLeftPos(2)));        %�յ��糡�Ƕȣ���oYΪ�ᣬ������תΪ��    
if thetaVorL < 0
   thetaVorL = thetaVorL + pi;
end

WVorLVector = [0 -WVorL*sin(thetaVorL) WVorL*cos(thetaVorL)]';                                  %�г���ά�ֽ�(�Զ��������ϵ)


%�Ҳ�(R)�����������
rVorR = sqrt((receiverPos(2)-wingTipRightPos(2))^2 + (receiverPos(3)-wingTipRightPos(3))^2);
tVorR = -receiverPos(1)/airSpeed1;
TVorR = vortexStrength;
vVorR = 0.06*TVorR;
rVorCoreR = 2.24*sqrt(abs(vVorR*tVorR));

WVorR = TVorR*rVorR/(2*pi*(rVorR^2+rVorCoreR^2))*(1-exp(-rVorR^2/(4*vVorR*tVorR)));    
thetaVorR = atan((receiverPos(3)-wingTipRightPos(3))/(-receiverPos(2)+wingTipRightPos(2)));             %�糡�Ƕȣ���-oyΪ�ᣬ����Ϊ��    
if (-receiverPos(2)+wingTipRightPos(2)) < 0
   thetaVorR = thetaVorR + pi;
end

WVorRVector = [0 WVorR*sin(thetaVorR) WVorR*cos(thetaVorR)]';   


%��������(Wing����ĸW��ʾ)��Ч��������
rVorW = sqrt((receiverPos(1)-wingTipRightPos(1))^2 + (receiverPos(3)-wingTipRightPos(3))^2);            %���������߾���
tVorW = -receiverPos(1)/airSpeed1;

LVorLength = sqrt((receiverPos(1)-wingTipLeftPos(1))^2 + (receiverPos(2)-wingTipLeftPos(2)*pi/4)^2+ (receiverPos(3)-wingTipLeftPos(3))^2);       %����������
RVorLength = sqrt((receiverPos(1)-wingTipRightPos(1))^2 + (receiverPos(2)-wingTipRightPos(2)*pi/4)^2+ (receiverPos(3)-wingTipRightPos(3))^2);    %����������

gamaLCos = (receiverPos(2)-wingTipLeftPos(2)*pi/4)/LVorLength;                                          %��������Ƕ����ң�oyΪ������Ϊ��
gamaRCos = (-receiverPos(2)+wingTipRightPos(2)*pi/4)/RVorLength ;                                       %���Ҳ����Ƕ����ң�-oyΪ������Ϊ��

TVorW = vortexStrength*(gamaLCos + gamaRCos)/2*4/pi;                                                    %�����������޳����У��ù�ʽ���¼�����ǿ��
vVorW = 0.06*TVorW;
rVorCoreW = 2.24*sqrt(abs(vVorW*tVorW));

WVorW = TVorW*rVorW/(2*pi*(rVorW^2+rVorCoreW^2))*(1-exp(-rVorW^2/(4*vVorW*tVorW)));         
thetaVorW = atan((receiverPos(3)-wingTipRightPos(3))/(-receiverPos(1)+wingTipRightPos(1)));              %�糡�Ƕȣ���-oxΪ�ᣬ����Ϊ��  
if (-receiverPos(1)+wingTipRightPos(1)) < 0
   thetaVorW = thetaVorW + pi;
end

WVorWVector = [WVorW*sin(thetaVorW), 0 , WVorW*cos(thetaVorW)]';   


%���(L)β����������
rVorLT = sqrt((receiverPos(2)-wingTipLeftPos(2))^2 + (receiverPos(3)-wingTipLeftPos(3))^2);      
tVorLT = -(receiverPos(1)-wingTipLeftPos(1))/airSpeed1;                                                                
TVorLT = vortexStrength/30;                                                                         
vVorLT = 0.06*TVorLT;                                                                             
rVorCoreLT = 2.24*sqrt(abs(vVorLT*tVorLT));                                                             

WVorLT = TVorLT*rVorLT/(2*pi*(rVorLT^2+rVorCoreLT^2))*(1-exp(-rVorLT^2/(4*vVorLT*tVorLT)));             %�յ��糡��С   
thetaVorLT = atan((receiverPos(3)-wingTipLeftPos(3))/(receiverPos(2)-wingTipLeftPos(2)));               %�յ��糡�Ƕȣ���oYΪ�ᣬ������תΪ��    
if (receiverPos(2)-wingTipLeftPos(2)) < 0
   thetaVorLT = thetaVorLT + pi;
end

WVorLTVector = [0 WVorLT*sin(thetaVorLT) -WVorLT*cos(thetaVorLT)]';                                     %�г���ά�ֽ�(�Զ��������ϵ)


%�Ҳ�(R)β����������
rVorRT = sqrt((receiverPos(2)-tailTipRightPos(2))^2 + (receiverPos(3)-tailTipRightPos(3))^2);
tVorRT = -(receiverPos(1)-wingTipLeftPos(1))/airSpeed1;
TVorRT = vortexStrength/30;
vVorRT = 0.06*TVorRT;
rVorCoreRT = 2.24*sqrt(abs(vVorRT*tVorRT));

WVorRT = TVorRT*rVorRT/(2*pi*(rVorRT^2+rVorCoreRT^2))*(1-exp(-rVorRT^2/(4*vVorRT*tVorRT)));    
thetaVorRT = atan((receiverPos(3)-tailTipRightPos(3))/(-receiverPos(2)+tailTipRightPos(2)));            %�糡�Ƕȣ���-oyΪ�ᣬ����Ϊ��    
if (-receiverPos(2)+tailTipRightPos(2)) < 0
   thetaVorRT = thetaVorRT + pi;
end

WVorRTVector = [0 -WVorRT*sin(thetaVorRT) -WVorRT*cos(thetaVorRT)]';   

%����β��(Tail����ĸT��ʾ)��Ч��������
rVorT = sqrt((receiverPos(1)-tailTipRightPos(1))^2 + (receiverPos(3)-tailTipRightPos(3))^2);            %���������߾���
tVorT = -(receiverPos(1)-wingTipLeftPos(1))/airSpeed1;

LVorLengthT = sqrt((receiverPos(1)-tailTipLeftPos(1))^2 + (receiverPos(2)-tailTipLeftPos(2)*pi/4)^2+ (receiverPos(3)-tailTipLeftPos(3))^2);       %����������
RVorLengthT = sqrt((receiverPos(1)-tailTipRightPos(1))^2 + (receiverPos(2)-tailTipRightPos(2)*pi/4)^2+ (receiverPos(3)-tailTipRightPos(3))^2);    %����������

gamaLCosT = (receiverPos(2)-tailTipLeftPos(2)*pi/4)/LVorLengthT;                                        %��������Ƕ����ң�oyΪ������Ϊ��
gamaRCosT = (-receiverPos(2)+tailTipRightPos(2)*pi/4)/RVorLengthT ;                                     %���Ҳ����Ƕ����ң�-oyΪ������Ϊ��

TVorT = vortexStrength/30*(gamaLCosT + gamaRCosT)/2*4/pi;                                               %�����������޳����У��ù�ʽ���¼�����ǿ��
vVorT = 0.06*TVorT;
rVorCoreT = 2.24*sqrt(abs(vVorT*tVorT));

WVorT = TVorT*rVorT/(2*pi*(rVorT^2+rVorCoreT^2))*(1-exp(-rVorT^2/(4*vVorT*tVorT)));     
thetaVorT = atan((receiverPos(3)-tailTipRightPos(3))/(-receiverPos(1)+tailTipRightPos(1)));             %�糡�Ƕȣ���-oxΪ�ᣬ����Ϊ��  
if (-receiverPos(1)+tailTipRightPos(1)) < 0
   thetaVorT = thetaVorT + pi;
end

WVorTVector = [-WVorT*sin(thetaVorT), 0 , -WVorT*cos(thetaVorT)]';   


WTotalVector = WVorLVector + WVorRVector + WVorWVector + WVorLTVector + WVorRTVector + WVorTVector;

%����糡�����ͻ����������
y = WTotalVector;