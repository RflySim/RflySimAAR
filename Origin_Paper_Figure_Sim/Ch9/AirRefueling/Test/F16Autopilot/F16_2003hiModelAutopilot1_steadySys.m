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

A_lon=A([5,7,8,11,13,14],[5,7,8,11,13,14]);
B_lon=B([5,7,8,11,13,14],1:2);

Q_lon=diag([10 100 10 10 0 0]);

%%%R越大相应的输入量越小，控制越弱，响应时间越长
R_lon=diag([50 50]);
[k_lon,p_lon,e_lon]=lqr(A_lon,B_lon,Q_lon,R_lon);
%eig(A_lon-B_lon*k_lon)

Kp_lon=k_lon;



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

A_la=A([4,6,9,10,12,15,16],[4,6,9,10,12,15,16]);
B_la=B([4,6,9,10,12,15,16],3:4);

Q_la=diag([10 10 10 10 10 0 0]);

%%%R越大相应的输入量越小，控制越弱，响应时间越长
R_la=diag([5 5]);
[k_la,p_la,e_la]=lqr(A_la,B_la,Q_la,R_la);

eig(A_la-B_la*k_la)

Kp_la=k_la;

% 
% %%-------------------total equation-------------------------------%%
Kp=zeros(4,18);
Kp(1:2,[5,7,8,11,14])=Kp_lon;
Kp(3:4,[4,6,9,10,12,15,16])=Kp_la;

