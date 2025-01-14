%path(path,'F16Sim 2003/');

fi_flag = 0;  %选择高保真或低保真气动参数

mass = 636.94*14.59428;    %kg
Inertia=[9496,0,-982.0;0,55814.0,0;-982.0,0,63100.0]*1.35583; %kg.m^2

xme_0=[0,0,-9843*0.3048];%Initial position in inertial axes [Xe,Ye,Ze]:
Vmw=[393.72*0.3048,0,0];%Initial velocity in body axes [U,v,w]:
Euler_0=[0,0,0];%Initial Euler orientation [roll, pitch, yaw]:
pm_0=[0,0,0];%Initial body rotation rates [p,q,r]:

S_ref=27.870912;%Reference area (m)
b_ref=9.144;%Reference span (m)
d_ref=3.450336;%Reference length or mean chord length (m)

x_cg=0.09144;%Center of Gravity
x_ref=0.10668;%Center if Pressure
alpha0=1;%Initialize LF_state with -alpha0 value in degrees


altitude=9843;%(ft)
velocity=393.72;%(ft/s)
if (fi_flag == 1)
    % Calculating qbar, ps and steady state leading edge flap deflection:
    % (see pg. 43 NASA report)
    rho0 = 2.377e-3; tfac = 1 - 0.703e-5*altitude;
    temp = 519*tfac; 
    if (altitude >= 35000) 
        temp = 390; 
    end;
    rho = rho0*tfac^4.14;
    qbar = 0.5*rho*velocity^2;
    ps = 1715*rho*temp;
    
    dLEF = 1.38*alpha0*180/pi - 9.05*qbar/ps + 1.45;
    
elseif (fi_flag_Simulink == 0)
    dLEF = 0.0;
end

% Verify that the calculated leading edge flap
% have not been violated.
if (dLEF > 25)
    dLEF = 25;
elseif (dLEF < 0)
    dLEF = 0;
end;

trim_thrust=5000;
trim_ele= -0.09;
trim_ail=-0.01;
trim_rud=0.01;
