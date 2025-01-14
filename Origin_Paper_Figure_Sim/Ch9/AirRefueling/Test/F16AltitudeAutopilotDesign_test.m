clear;
clc;

%%状态变量h,theta,v,alpha,q,T,el 角度单位为弧度，长度单位为ft，油门单位为lbs
A=[0	393.72	0	-393.72	0	0	0
0	0	0	0	1	0	0
0.000111135	-32.17	-0.018054928	-8.065022573	-1.846855155	0.001559526	0.000437475
2.52E-06	3.76E-15	-0.000409721	-0.667371723	0.927561102	-4.60E-07	-0.001426346
7.98E-12	0	-1.30E-09	-0.742601	-0.850870526	0	-0.086580984
0	0	0	0	0	-1	0
0	0	0	0	0	0	-20.2


];

%%输入依次对应油门和升降舵

B=[0	0
0	0
0	0
0	0
0	0
1	0
0	20.2

];
%C_alpha=[0 0 0 57.29577951 0 0 0];
%C_q=[0 0 0  0 57.29577951 0 0];
%C_theta=[0 57.29577951 0 0 0 0 0];
%C_h=[0.3048 0 0 0 0 0 0];

%输出一次为alpha q theta h 单位为度和米
C=[0 0 0 57.29577951 0 0 0;
    0 0 0  0 57.29577951 0 0;
    0 57.29577951 0 0 0 0 0;
    1 0 0 0 0 0 0;
    ];


D=[0	0
0	0
0	0
0	0
];

%方便根轨迹设计，取给B加反相器
plant_actual=ss(A,-B,C,D);

[a,b,c,d]=ssdata(plant_actual);
%rlocus(a,b,c(1,:),0)

k_alpha=0;
ac1=a-b(:,2)*k_alpha*c(1,:);
sys2=ss(ac1,b(:,2),c(2,:),0);
zero_p=3;pole_p=1;
lag=ss(-pole_p,1,zero_p-pole_p,1);

sys3=sys2;
[a,b,c,d]=ssdata(sys3);

%rlocus(a,b,c,d)

k_q=0.5;
ac2=a-b*k_q*c;

c_h=[1 0 0 0 0 0 0];
c_t=[0 57.29577951 0 0 0 0 0];

%rlocus(ac2,b,c,d)

kp=0.6;
ac3=ac2-b*kp*c_t;

[z,p,k]=ss2zp(ac3,kp*b,c_h,0)

sys4=ss(ac3,kp*b,c_h,0);

%[a,b,c,d]=ssdata(sys4);
%margin(a,b,c,d)

%hold on
[a,b,c,d]=ssdata(sys4);
%margin(a,b,c,d)

pole_l=3;
lead=ss(-pole_l,pole_l,-0.875,1);
sys5=series(lead,sys4);
k_ll=0.3;
[a,b,c,d]=ssdata(sys5);
%margin(a,k_ll*b,c,d)
hold on
lag=ss(-0.01,0.01,8,1);
sys6=series(lag,sys5);
[a,b,c,d]=ssdata(sys6);
%margin(a,k_ll*b,c,d)

ac4=a-k_ll*b*c;


sys7=ss(ac4,k_ll*b,c,0);
step(sys7,30)
[z,p,k]=ss2zp(ac4,k_ll*b,c,0)

%rlocus(ac4,k_ll*b,c,0)
grid on

%rlocus(ac3,kp*b,c_h,0)
%ac4=ac3-b*c_h;
%rlocus(ac2,b,c,0)
%[z,p,k]=ss2zp(ac2,b,c,0)
%rlocus(ac2,b,c,0)
%rlocus(ac1,b(:,2),c(2,:),0)
%hold on

%  t=[0:0.02:10];
%  u=[-1.8*ones(1,51) 1.8*ones(1,50) zeros(1,400)]';
%  [y,x]=lsim(ac2,b,c,0,u,t);
%  plot(t,y,t,u)
%hold on
%sys3=ss(ac4,kp*b,c_h,0);
%step(sys3,100)

% 
% %k_q=2;
% %ac1=a-b*[k_q 0 0]*c;
% %sysqClosed=ss(ac1,b,c(2:3,:),d(2:3));
% 
% 
% [a,b,c,d]=ssdata(sysqClosed);
% %[z,p,k]=ss2zp(a,b,c(1,:),0)
% %rlocus(a,b,c(1,:),0)
% k_theta=1.9;
% ac1=a-b*[k_theta 0]*c;
% sysThetaClosed=ss(ac1,k_theta*b,c(2,:),d(2));
% 
% [a,b,c,d]=ssdata(sysThetaClosed);
% 
% %[z,p,k]=ss2zp(a,b,c,d)
% 
% %margin(a,b,c,d)
% %figure
% %[z,p,k]=ss2zp(a,b,c,d)
% %rlocus(ac1,b,c(2,:),0)
