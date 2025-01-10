
close all
clear
clc

load('hose_initial.mat')

N = 10;

theta10 = theta1_100; %pi/6*ones(1,N);
theta20 = theta2_100; %zeros(1,N);
dtheta10 = zeros(1,N);
dtheta20 = zeros(1,N);

height = 3000;
vt0 = [120;0;0];
pt0 = [0;0;0];

length = 15;
l_density = 4.1;
l1 = 2;
l0 = (length-l1)/(N-1);
m0 = l0*l_density;
Rl = 0.0336;

Mdr = 29.5;
Rdr = 0.305;
Cdr_ = 0.8;

T_reel_initial = 1610; % ע�����ֵ��¶����ߵ����׶�������йأ�
                       % �����׶�׵Ĳ�����������Ҫ����ͨ��v1��ķ������
t_step = 100;
%HDU����������
k_reel = 0.5;
kd=500;

save('hose_parameter4dock.mat')

