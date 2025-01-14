clear;

% linearized model : x_dot = A * x + B * u
%   
%   ----State Variables --------                          
%01      x = [ npos  ( ft )        - north position              
%02            epos  ( ft )        - east position    
%03            h     ( ft )        - height 
%04            phi   ( rad )       - Euler angle  (roll)   
%05            theta ( rad )       - Euler angle  (pitch)     
%06            psi   ( rad )       - Euler angle  (yaw)  
%07            Vt    ( ft/sec)     - total speed   
%08            alpha ( rad )       - angle of attack   
%09            beta  ( rad )       - sideslip angle 
%10            p     ( rad/sec )   - roll rate   
%11            q     ( rad/sec )   - pitch rate
%12            r     ( rad/sec )   - yaw rate              
%13            Thr   ( - )         - throttle actuator  
%14            Ele   ( - )         - elevon actuator    
%15            Ail   ( - )         - aileron actuator  
%16            Rud   ( - )         - rudder actuator  
%17            Q     ( ft )        - dynamic pressure  
%18            Ps    ( ft )        - static pressure   
%          ];            
%                                                         
%   ---- Control Variables --------                       
%      u = [ delta_t   ( lbs )     - throttle setting  1000~19000   
%            delta_e   ( deg )     - elevon deflection  +-30    
%            delta_a   ( deg )     - aileron deflection +-30    
%            delta_r   ( deg )     - rudder deflection  +-30
%           ];   


A=[0	0	0	0	-2.55E-09	0	1	0	0	0	0	0	0	0	0	0	0	0
0	0	0	-45.41645538	0	393.72	0	0	393.72	0	0	0	0	0	0	0	0	0
0	0	0	0	393.72	0	0	-393.72	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	1	0	0.116127357	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	1	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	1.006720201	0	0	0	0	0	0
0	0	0.000111135	0	-32.17	0	-0.018054928	-8.065022573	-0.513279483	0	-1.846855155	0	0.001559526	0.000437475	0	0	0.04140394	0
0	0	2.52E-06	0	3.76E-15	0	-0.000409721	-0.667371723	0.002506663	0	0.927561102	0	-4.60E-07	-0.001426346	0	0	0.000310857	0
0	0	2.97E-08	0.081162385	0	0	-2.41E-06	-0.001504132	-0.172588697	0.116271401	0	-0.987379385	0	0	0.000195154	0.000491154	-8.31E-06	0
0	0	-1.46E-12	0	0	0	2.37E-10	1.466101862	-17.70621848	-2.011595253	0	0.673466992	0	-0.000591216	-0.304265853	0.05827256	-0.00373523	0
0	0	7.98E-12	0	0	0	-1.30E-09	-0.742601	0.023953046	0	-0.850870526	0	0	-0.086580984	0	0	-0.012064992	0
0	0	4.94E-10	0	0	0	-8.03E-08	-0.014838266	3.542187625	-0.051673814	0	-0.286518102	0	0.001061005	-0.012608703	-0.029299811	0.000276073	0
0	0	0	0	0	0	0	0	0	0	0	0	-1	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	0	0	-20.2	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	0	0	0	-20.2	0	0	0
0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	-20.2	0	0
0	0	-4.70E-05	0	0	0	-0.031623327	1162.76729	0	0	0	0	0	0	0	0	-7.352941176	10.14705882
0	0	0	0	0	0	0	-415.3944015	0	0	0	0	0	0	0	0	0	-7.25
];

B=[0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
0	0	0	0
1	0	0	0
0	20.2	0	0
0	0	20.2	0
0	0	0	20.2
0	0	0	0
0	0	0	0
];

%%%输出一次为xd,h,yd
C=[1,zeros(1,17);
    0,0,1,zeros(1,15);
    0,1,zeros(1,16)];

%%% change throttle input delta_t's range to 1~19
%%% to make sure four inputs have the same orders of magntiude
B(:,1)=B(:,1)*1000;



%%-------------------Longitudinal equation-------------------------------%%

% linearized model : x_lon_dot = A_lon * x_lon + B_lon * u_lon
%   
%   ----State Variables --------  
%   01.npos , 02.h , 03.theta , 04.Vt , 05.alpha , 06.q , 07.Thr , 08.Ele
%                                                         
%   ---- Control Variables --------  
%   delta_t delta_e
%
%   ---- Output --------  
%   C_lo_xd_h  -  npos , h
%

A_lon=A([1,3,5,7,8,11,13,14],[1,3,5,7,8,11,13,14]);
B_lon=B([1,3,5,7,8,11,13,14],1:2);
C_lon_xd_h=[1 zeros(1,7);
    0 1 zeros(1,6)];

%增广系统矩阵，加入h和xd的误差积分项
AA_lon=[A_lon,zeros(8,2);-C_lon_xd_h,zeros(2,2)];
BB_lon=[B_lon;zeros(2,2)];
Q_lon=diag([4 10 10 1 10 10 0 0 1 3]);

%%%R越大相应的输入量越小，控制越弱，响应时间越长
R_lon=diag([50 50]);
[k_lon,p_lon,e_lon]=lqr(AA_lon,BB_lon,Q_lon,R_lon);

Kp_lon=k_lon(:,1:8);
Ki_lon=-k_lon(:,9:10);


%%-------------------lateral equation-------------------------------%%

% linearized model : x_la_dot = A_la * x_la + B_la * u_la
%   
%   ----State Variables --------  
%   01.epos , 02.phi , 03.psi , 04.beta , 05.p , 06.r , 07.Ail , 08.Rud 
%                                                         
%   ---- Control Variables --------  
%   delta_a delta_r
%
%   ---- Output --------  
%   C_la_yd  -  epos
%

A_la=A([2,4,6,9,10,12,15,16],[2,4,6,9,10,12,15,16]);
B_la=B([2,4,6,9,10,12,15,16],3:4);
C_la_yd=[1 zeros(1,7)];

%增广系统矩阵，加入h和xd的误差积分项
AA_la=[A_la,zeros(8,1);-C_la_yd,zeros(1,1)];
BB_la=[B_la;zeros(1,2)];
Q_la=diag([10 2 4 4 2 2 0 0 4]);

%%%R越大相应的输入量越小，控制越弱，响应时间越长
R_la=diag([500 500]);
[k_la,p_la,e_la]=lqr(AA_la,BB_la,Q_la,R_la);

eig(AA_la-BB_la*k_la)

Kp_la=k_la(:,1:8);
Ki_la=-k_la(:,9);


%%-------------------total equation-------------------------------%%
Kp=zeros(4,18);
Kp(1:2,[1,3,5,7,8,11,13,14])=Kp_lon;
Kp(3:4,[2,4,6,9,10,12,15,16])=Kp_la;

Ki=zeros(4,3);
Ki(1:2,1:2)=Ki_lon;
Ki(3:4,3)=Ki_la;



%%其他的一些常数
rad2degree=180/pi;
Kc=diag([0.3048,0.3048,0.3048,rad2degree,rad2degree,rad2degree,0.3048,rad2degree,rad2degree,rad2degree,rad2degree,rad2degree]);
Kc=[Kc,zeros(12,6)];

Kc=[
0.3048	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0.3048	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0.3048	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	57.29577951	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	57.29577951	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	57.29577951	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0.3048	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	57.29577951	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	57.29577951	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	57.29577951	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	57.29577951	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	57.29577951	0	0	0	0	0	0
0	0	1.47E-06	0	0.000124324	0	-0.000238787	0.185224164	0	0	0.008874503	0	4.88E-05	0.003173487	0	0	0	0
0	0	8.66E-16	-0.000124324	0	0	-1.41E-13	0	-2.296767309	-0.014355754	0	0.066891704	0	0	0.001957696	0.005745682	0	0
0	0	-5.53E-06	0	0	0	0.000898246	7.54488061	0	0	0.83270499	0	0	0.015232738	0	0	0	0
0	0	1.38E-06	0	0	0	0.000928168	0	0	0	0	0	0	0	0	0	0	0
0	0	-0.00428099	0	0	0	0.695487318	0	0	0	0	0	0	0	0	0	0	0
0	0	-0.056813516	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
];

Csta=zeros(18,6);
Csta(10:12,4:6)=diag([1/0.3048,1/0.3048,1/0.3048]);
Csta(7:9,1:3)= [0 0 0;0 0 1/120;0 1/120 0];


alpha_e=0.115609527;
I1=[cos(alpha_e) 0 -sin(alpha_e);
    0   1   0;
    sin(alpha_e) 0  cos(alpha_e)];
Cb_e=[I1,zeros(3,3);
    zeros(3,3),I1];
B_wTur=A*Csta*Cb_e;



C2m=0.3048*C;
C2m=[C2m(1,:);
     C2m(3,:);
     -C2m(2,:)
];
m2ft=1/0.3048;

X1_0=zeros(18,1);

C_attitude=[zeros(3,3),eye(3),zeros(3,12)];

trim_state=[
0
0
9843
0
1.14E-17
0
393.72
1.14E-17
0
0
0
0
1000
-1.549425813
-1.24E-10
-4.78E-09
0
0
];
K_control=diag([1000,1,1,1]);

trim_thrust=2279.08519954656;
trim_control=[-2.979731649
0.008746079
0.068030216
];