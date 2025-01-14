% linearized model : x_dot = A * x + B * u
%                       y   = C * x + D * u
%   
%   ----State Variables --------                          
%      x = [ vt    ( ft/sec )    - velocity               
%            h     ( ft )        - altitude               
%            alpha ( rad )       - angle of attack        
%            theta ( rad )       - Euler angle            
%            Q     ( rad/sec )   - pitch rate             
%            pow                 - power                  
%            beta  ( rad )       - sideslip angle         
%            phi   ( rad )       - Euler angle            
%            P     ( rad/sec )   - roll rate              
%            R     ( rad/sec )   - yaw rate 
%          ];            
%                                                         
%   ---- Control Variables --------                       
%      u = [ thtl ( 0 ~ 1.0 )    - throttle setting       
%            el   ( deg )        - elevon deflection      
%            ail  ( deg )        - aileron deflection     
%            rdr  ( deg )        - rudder deflection 
%           ];   


A=[
       -0.0196   -0.0000   -3.5776  -31.6936   -1.9016    0.2882    0.0000   -0.0000   -0.0000   -0.0000
         0         0 -387.8407  387.8407         0         0         0    0.0000         0         0
   -0.0004    0.0000   -0.6392    0.0000    0.9263   -0.0001   -0.0000         0    0.0000    0.0000
         0         0         0         0    1.0000         0         0         0         0         0
    0.0000   -0.0000   -1.0217         0   -0.8513         0   -0.0000         0         0   -0.0029
         0         0         0         0         0   -1.0000         0         0         0         0
    0.0000   -0.0000   -0.0000   -0.0000   -0.0000    0.0000   -0.1802    0.0800    0.1166   -0.9873
         0         0         0         0         0         0         0         0    1.0000    0.1164
   -0.0000    0.0000    0.0000         0    0.0003         0  -14.8086         0   -2.0218    0.6833
   -0.0000    0.0000    0.0000         0    0.0025         0    4.4140         0   -0.0429   -0.2861
];

B=[
         0    0.0323   -0.0000   -0.0000
         0         0         0         0
         0   -0.0013         0         0
         0         0         0         0
         0   -0.0833         0         0
   34.0634         0         0         0
         0    0.0000    0.0002    0.0005
         0         0         0         0
         0         0   -0.3305    0.0576
         0         0   -0.0140   -0.0292
];


%给原系统增加新的状态变量变为：xd,vt,h,alpha,theta,Q,pow, yd,beta,phi,P,R
A_full=[0,1,zeros(1,9);zeros(10,1),A];   %增加x轴位移状态量xd到原状态第一个位置
A_full=[A_full(1:7,1:7),zeros(7,1),A_full(1:7,8:11);  %增加侧向位移yd到第8个位置 在pow和beta之间
        zeros(1,8),387.8407,387.8407,0,0;
        A_full(8:11,1:7),zeros(4,1),A_full(8:11,8:11)];  

B_full=[zeros(1,4);B(1:6,1:4);zeros(1,4);B(7:10,1:4)];



%-----------------------------纵向控制--LQR------------------------------------

%解耦，纵向方程xd,vt,h,alpha,theta,Q,pow，输入 推力thtl( 0 ~ 1.0 )，升降舵el( deg )
A_lon=A_full(1:7,1:7);
B_lon=B_full(1:7,1:2);


C_xd_h=[1   0   0   0   0   0   0   
 0   0	1	0	0	0	0
];

%增广系统矩阵，加入h和xd的误差积分项
AA_lon=[A_lon,zeros(7,2);-C_xd_h,zeros(2,2)];
BB_lon=[B_lon;zeros(2,2)];

%Q=diag([10  10 10 10 10 10 5 2 10]);
%R=diag([0.5 1.5]);

Q_lon=diag([8 20 20 5 10 5 5 2 10]);
R_lon=diag([0.5 1.5]);

%LQR方法求出反馈增益矩阵和积分增益矩阵
[k_lon,p_lon,e_lon]=lqr(AA_lon,BB_lon,Q_lon,R_lon);
Kp_lon=k_lon(:,1:7);
Ki_lon=-k_lon(:,8:9);

%%eig(AA_lon-BB_lon*k_lon)



%---------------------------横向控制--LQR--------------------------------------
%解耦，横向方程yd,beta,phi,P,R，输入 副翼ail( deg )， 方向舵rdr( deg )
A_la=A_full(8:12,8:12);
B_la=B_full(8:12,3:4);


C_yd=[1   0   0   0   0];

%增广系统矩阵，加入h和xd的误差积分项
AA_la=[A_la,zeros(5,1);-C_yd,zeros(1,1)];
BB_la=[B_la;zeros(1,2)];

%Q=diag([10  10 10 10 10 10 5 2 10]);
%R=diag([0.5 1.5]);

Q_la=diag([50 5 5 50 30 100]);
R_la=diag([0.01 0.01]);

%LQR方法求出反馈增益矩阵和积分增益矩阵
[k_la,p_la,e_la]=lqr(AA_la,BB_la,Q_la,R_la);
Kp_la=k_la(:,1:5);
Ki_la=-k_la(:,6);

eig(AA_la-BB_la*k_la);


%整体模型
C_xd_h_yd=[C_xd_h,zeros(2,5);
           zeros(1,7),C_yd];
Kp=[Kp_lon,zeros(2,5);
    zeros(2,7),Kp_la];
Ki=[Ki_lon,zeros(2,1);
    zeros(2,2),Ki_la];

