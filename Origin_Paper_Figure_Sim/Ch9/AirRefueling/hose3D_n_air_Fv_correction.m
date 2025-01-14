function [sys,x0,str,ts,simStateCompliance] = hose3D_n_air_Fv_correction(t,x,u,flag)
%SFUNTMPL General M-file S-function template
%   With M-file S-functions, you can define you own ordinary differential
%   equations (ODEs), discrete system equations, and/or just about
%   any type of algorithm to be used within a Simulink block diagram.
%
%   The general form of an M-File S-function syntax is: 
%       [SYS,X0,STR,TS,SIMSTATECOMPLIANCE] = SFUNC(T,X,U,FLAG,P1,...,Pn)
%
%   What is returned by SFUNC at a given point in time, T, depends on the
%   value of the FLAG, the current state vector, X, and the current
%   input vector, U.
%
%   FLAG   RESULT             DESCRIPTION
%   -----  ------             --------------------------------------------
%   0      [SIZES,X0,STR,TS]  Initialization, return system sizes in SYS,
%                             initial state in X0, state ordering strings
%                             in STR, and sample times in TS.
%   1      DX                 Return continuous state derivatives in SYS.
%   2      DS                 Update discrete states SYS = X(n+1)
%   3      Y                  Return outputs in SYS.
%   4      TNEXT              Return next time hit for variable step sample
%                             time in SYS.
%   5                         Reserved for future (root finding).
%   9      []                 Termination, perform any cleanup SYS=[].
%
%
%   The state vectors, X and X0 consists of continuous states followed
%   by discrete states.
%
%   Optional parameters, P1,...,Pn can be provided to the S-function and
%   used during any FLAG operation.
%
%   When SFUNC is called with FLAG = 0, the following information
%   should be returned:
%
%      SYS(1) = Number of continuous states.
%      SYS(2) = Number of discrete states.
%      SYS(3) = Number of outputs.
%      SYS(4) = Number of inputs.
%               Any of the first four elements in SYS can be specified
%               as -1 indicating that they are dynamically sized. The
%               actual length for all other flags will be equal to the
%               length of the input, U.
%      SYS(5) = Reserved for root finding. Must be zero.
%      SYS(6) = Direct feedthrough flag (1=yes, 0=no). The s-function
%               has direct feedthrough if U is used during the FLAG=3
%               call. Setting this to 0 is akin to making a promise that
%               U will not be used during FLAG=3. If you break the promise
%               then unpredictable results will occur.
%      SYS(7) = Number of sample times. This is the number of rows in TS.
%
%
%      X0     = Initial state conditions or [] if no states.
%
%      STR    = State ordering strings which is generally specified as [].
%
%      TS     = An m-by-2 matrix containing the sample time
%               (period, offset) information. Where m = number of sample
%               times. The ordering of the sample times must be:
%
%               TS = [0      0,      : Continuous sample time.
%                     0      1,      : Continuous, but fixed in minor step
%                                      sample time.
%                     PERIOD OFFSET, : Discrete sample time where
%                                      PERIOD > 0 & OFFSET < PERIOD.
%                     -2     0];     : Variable step discrete sample time
%                                      where FLAG=4 is used to get time of
%                                      next hit.
%
%               There can be more than one sample time providing
%               they are ordered such that they are monotonically
%               increasing. Only the needed sample times should be
%               specified in TS. When specifying more than one
%               sample time, you must check for sample hits explicitly by
%               seeing if
%                  abs(round((T-OFFSET)/PERIOD) - (T-OFFSET)/PERIOD)
%               is within a specified tolerance, generally 1e-8. This
%               tolerance is dependent upon your model's sampling times
%               and simulation time.
%
%               You can also specify that the sample time of the S-function
%               is inherited from the driving block. For functions which
%               change during minor steps, this is done by
%               specifying SYS(7) = 1 and TS = [-1 0]. For functions which
%               are held during minor steps, this is done by specifying
%               SYS(7) = 1 and TS = [-1 1].
%
%      SIMSTATECOMPLIANCE = Specifices how to handle this block when saving and
%                           restoring the complete simulation state of the
%                           model. The allowed values are: 'DefaultSimState',
%                           'HasNoSimState' or 'DisallowSimState'. If this value
%                           is not speficified, then the block's compliance with
%                           simState feature is set to 'UknownSimState'.


%   Copyright 1990-2009 The MathWorks, Inc.
%   $Revision: 1.18.2.4 $

%
% The following outlines the general structure of an S-function.
%

global N l rou;
N = 20;
l = 14.3256/N;
rou = 4.0925;         %软管线密度Kg/m;

switch flag,

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0,
    [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes;

  %%%%%%%%%%%%%%%
  % Derivatives %
  %%%%%%%%%%%%%%%
  case 1,
    sys=mdlDerivatives(t,x,u);

  %%%%%%%%%%
  % Update %
  %%%%%%%%%%
  case 2,
    sys=mdlUpdate(t,x,u);

  %%%%%%%%%%%
  % Outputs %
  %%%%%%%%%%%
  case 3,
    sys=mdlOutputs(t,x,u);

  %%%%%%%%%%%%%%%%%%%%%%%
  % GetTimeOfNextVarHit %
  %%%%%%%%%%%%%%%%%%%%%%%
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u);

  %%%%%%%%%%%%%
  % Terminate %
  %%%%%%%%%%%%%
  case 9,
    sys=mdlTerminate(t,x,u);

  %%%%%%%%%%%%%%%%%%%%
  % Unexpected flags %
  %%%%%%%%%%%%%%%%%%%%
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));

end

% end sfuntmpl

%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes
global N;
%
% call simsizes for a sizes structure, fill it in and convert it to a
% sizes array.
%
% Note that in this example, the values are hard coded.  This is not a
% recommended practice as the characteristics of the block are typically
% defined by the S-function parameters.
%
sizes = simsizes;

sizes.NumContStates  = 4*N;  
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 5*N;
sizes.NumInputs      = 6;   %前三个是尾点的加速度
                                         %后三个是空速与加油机的合速度
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

%
% initialize the initial conditions
%

% if N/10 == 1
%     load StaticPosition10.mat
% elseif N/10 == 2
%     load StaticPosition20.mat
% elseif N/3 == 1
%     load StaticPosition3.mat
% else
%     fprintf('N的给定有误，无对应的初始状态，须重新算相应的初始状态')
% end
load StaticPosition20_20140312.mat

global drogue;      %须先进行一次稳态位置的计算再进行引用
x0 = zeros(1,4*N);
for i = 1:4*N
    x0(1,i) = drogue(1,i);
%     x0(1,i) = 0;
end

% for i = 1:N
%     x0(i) = (N-i+1)*pi/(6*N);
% end


%
% str is always an empty matrix
%
str = [];

%
% initialize the array of sample times
%
ts  = [0 0];

% Specify the block simStateCompliance. The allowed values are:
%    'UnknownSimState', < The default setting; warn and assume DefaultSimState
%    'DefaultSimState', < Same sim state as a built-in block
%    'HasNoSimState',   < No sim state
%    'DisallowSimState' < Error out when saving or restoring the model sim state
simStateCompliance = 'UnknownSimState'; 

% end mdlInitializeSizes

%
%=============================================================================
% mdlDerivatives
% Return the derivatives for the continuous states.
%=============================================================================
%
function sys=mdlDerivatives(t,x,u)
global N l rou;
density = 0.844323529538532;       %大气密度0.7兆帕，25摄氏度
radius = 0.0336;        %管子的外半径
viscosity = 1.7894*10^-5; %空气运动粘度（m^2/s）!!!可能有问题

Ddr2 = 0.6096^2;      %伞套直径的平方!!!这里的换算可能有问题
Mdr =  29.4840;   %伞套的质量
%%%%规范状态变量%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   phi_i    :  x(i)       第i根杆纵角
%   theta_i  :  x(N+i)     第i根杆横角
%   dphi_i   :  x(2*N+i)   第i根杆纵角角速率
%   dtheta_i :  x(3*N+i)   第i根杆横角角速率
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%规范输入%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   ax： u(1)    第N质点x方向加速度
%   ay： u(2)    第N质点y方向加速度
%   az： u(3)    第N质点z方向加速度
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
n = zeros(3,N);
ndph = zeros(3,N);
ndth = zeros(3,N);

Fv = [u(1);u(2);u(3)];
v0 = [u(4);u(5);u(6)];      %空速与加油机的合速度

for i = 1:N
    n(1,i) = cos(x(i))*cos(x(N+i));
    n(2,i) = cos(x(i))*sin(x(N+i));
    n(3,i) = sin(x(i));             %杆的方向
end
for i = 1:N
    ndph(1,i) = -sin(x(i))*cos(x(N+i));
    ndph(2,i) = -sin(x(i))*sin(x(N+i));
    ndph(3,i) = cos(x(i));              %杆方向对纵角的导数
end
for i = 1:N
    ndth(1,i) = -cos(x(i))*sin(x(N+i));
    ndth(2,i) = cos(x(i))*cos(x(N+i));
    ndth(3,i) = 0;                      %杆方向对横角的导数
end

%%%%计算气动相关%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%——计算相对速度——————————————————————————
v = zeros(3,N);
vr = zeros(3,N);
v(:,1) = -l*(ndph(:,1)*x(2*N+1) + ndth(:,1)*x(3*N+1));
vr(:,1) = v(:,1) + v0;
for i = 2:N
    v(:,i) = v(:,i-1) - l*(ndph(:,i)*x(2*N+i) + ndth(:,i)*x(3*N+i));
    vr(:,i) = v(:,i) + v0;
end

%——计算雷诺数———————————————————————————
cosa = zeros(1,N);
sina = zeros(1,N);
Ref = zeros(1,N);
Red = zeros(1,N);
for i = 1:N
    if norm(vr(:,i)) ~= 0
        cosa(i) = vr(:,i)'*n(:,i)/norm(vr(:,i));
        sina(i) = sqrt(1-cosa(i)^2);
        if sina(i) ~= 0
            Ref(i) = (pi*radius/viscosity)*norm(vr(:,i))/sina(i);
        else
            Ref(i) = inf;
        end
        Red(i) = norm(vr(:,i))*2*radius/viscosity;
    else
        Ref(i) = 0;
    end
end

%——计算气动系数——————————————————————————
Cf = zeros(1,N);
Cd = zeros(1,N);
for i = 1:N
    %%%%Cf表%%%%%%%%%%%%%%%%%%%%%%%%
    if Ref(i)<=10^-2
        Cf(i) = 0;    %注意这里有改动
    elseif Ref(i)>10^-2 && Ref(i)<=10^4
        Cf(i) = 4.6409*Ref(i)^-0.6667;
    elseif Ref(i)>10^4 && Ref(i)<=10^10
        Cf(i) = 0.0464*Ref(i)^-0.1667;
    elseif Ref(i)>10^10
        Cf(i) = 0.001;
    end
    %%%%Cd表%%%%%%%%%%%%%%%%%%%%%%%%%
    if Red(i)<=10^-2
        Cd(i) = 0;   %注意这里有改动
    elseif Red(i)>10^-2 && Red(i)<=1
        Cd(i) = 10*Red(i)^-0.801;
    elseif Red(i)>1 && Red(i)<=180
        Cd(i) = 10*Red(i)^-0.4083;
    elseif Red(i)>180 && Red(i)<=4*10^5
        Cd(i) = 1.2;
    elseif Red(i)>4*10^5 && Red(i)<=4*10^6
        Cd(i) = 0.002128*Red(i)^0.3522;
    elseif Red(i)>4*10^6
        Cd(i) = 0.45;
    end
end


%——求气动力————————————————————————————
Df_mid = zeros(1,N);
Dd_mid = zeros(1,N);
Df = zeros(3,N);
Dd = zeros(3,N);
D = zeros(3,N);
vn = zeros(3,N);
for i = 1:N
    if vr(:,i)'*n(:,i)>0
        Df_mid(i) = -density*pi*radius*l*Cf(i)*(vr(:,i)'*n(:,i))^2;
    else
        Df_mid(i) = density*pi*radius*l*Cf(i)*(vr(:,i)'*n(:,i))^2;
    end
    Df(:,i) = Df_mid(i)*n(:,i);
    
    vn(:,i) = vr(:,i)-(vr(:,i)'*n(:,i))*n(:,i);
    if norm(vn(:,i)) ~= 0
        Dd_mid(i) = -density*radius*l*Cd(i)*norm(vn(:,i))^2;
        Dd(:,i) = Dd_mid(i)*vn(:,i)/norm(vn(:,i));
    else
        Dd(:,i) = [0;0;0];
    end
        
    D(:,i) = Df(:,i) + Dd(:,i);
end

%global MM;

if vr(:,N)'*vr(:,N) ~= 0
    Ddr = -1/2*density*vr(:,N)'*vr(:,N)*(pi*Ddr2/4)*(0.8)* vr(:,N)/norm(vr(:,N));
else
    Ddr = [0;0;0];
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

global MM1;
global MM2;

MM1=D;
MM2=Ddr;


%MM=Ref;
% %%%%计算合外力%%%%%%%%%%%%%%%%%%%%%%?
% Q = zeros(3,N);
% for i = 1:N-1
%     Q(:,i) = [0;0;m*g] + 1/2*(D(:,i)+D(:,i+1));
% end
% Q(:,N) = [0;0;(m+Mdr)*g] + 1/2*D(:,N) + Ddr;
Q = zeros(3,N);
for i = 1:N-1
    Q(:,i) = [0;0;-l*rou*10] + 1/2*(D(:,i)+D(:,i+1));
end
Q(:,N) = [0;0;-(l*rou + Mdr)*10] + 1/2*D(:,N) + Ddr + Fv;
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%求张力t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
T = zeros(N,N);
T(1,1) = 1;
T(1,2) = -n(:,1)'*n(:,2);
T(N,N-1) = -n(:,N-1)'*n(:,N);
T(N,N) = 2;             %注意这里很重要！！
for i = 2:N-1
    T(i,i-1) = -n(:,i-1)'*n(:,i);
    T(i,i) = 2;
    T(i,i+1) = -n(:,i)'*n(:,i+1);
end
q = zeros(N,1);
q(1,1) = l*rou*(l*(x(2*N+1)^2 + cos(x(1))^2*x(3*N+1)^2)) - n(:,1)'*Q(:,1);
% q(N,1) = l*rou*(l*(x(2*N+N)^2 + cos(x(N))^2*x(3*N+N)^2)) + n(:,N)'*Q(:,N);
for i = 2:N
    q(i,1) = l*rou*l*(x(2*N+i)^2 + cos(x(i))^2*x(3*N+i)^2) - n(:,i)'*(Q(:,i) - Q(:,i-1)) ; 
end
t = T\q; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

a = zeros(3,N);
for i = 1:N-1
    a(:,i) = (t(i)*n(:,i) - t(i+1)*n(:,i+1) +Q(:,i))/(l*rou);
end
a(:,N) = (t(N)*n(:,N) + Q(:,N))/(l*rou);

diff = zeros(1,4*N);
for i = 1:N
    diff(i) = x(2*N+i);
    diff(N+i) = x(3*N+i);
end

diff(2*N+1) = -1/l*ndph(:,1)'*a(:,1) - sin(x(1))*cos(x(1))*x(3*N+1)^2;
for i = 2:N
    diff(2*N+i) = -1/l*ndph(:,i)'*(a(:,i)-a(:,i-1)) - sin(x(i))*cos(x(i))*x(3*N+i)^2;
end
diff(3*N+1) = -1/l*ndth(:,1)'*a(:,1);
for i = 2:N
    diff(3*N+i) = -1/l*ndth(:,i)'*(a(:,i)-a(:,i-1));
end
sys = diff;


% end mdlDerivatives

%
%=============================================================================
% mdlUpdate
% Handle discrete state updates, sample time hits, and major time step
% requirements.
%=============================================================================
%
function sys=mdlUpdate(~,x,u)

sys = [];

% end mdlUpdate

%
%=============================================================================
% mdlOutputs
% Return the block outputs.
%=============================================================================
%
function sys=mdlOutputs(t,x,u)
global N l;
%%%%规范状态变量%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   phi_i    :  x(i)       第i根杆纵角
%   theta_i  :  x(N+i)     第i根杆横角
%   dphi_i   :  x(2*N+i)   第i根杆纵角角速率
%   dtheta_i :  x(3*N+i)   第i根杆横角角速率
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


rx = zeros(1,N);
ry = zeros(1,N);
rz = zeros(1,N);

rx(1) = -l*cos(x(1))*cos(x(N+1));
ry(1) = -l*cos(x(1))*sin(x(N+1));
rz(1) = -l*sin(x(1));
for i = 2:N
    rx(i) = rx(i-1)-l*cos(x(i))*cos(x(N+i));
    ry(i) = ry(i-1)-l*cos(x(i))*sin(x(N+i));
    rz(i) = rz(i-1)-l*sin(x(i));
end


O = zeros(1,5*N);

%%%%下面输出的是各个节点的位置%%%%%%%%%%%%%%%%%%%
for i = 1:N
     O(3*(i-1)+1) = rx(i);
     O(3*(i-1)+2) = ry(i);
     O(3*(i-1)+3) = -rz(i);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%为了求稳定的位置，把方向角进行输出%%%%%%%%%%%%%%%
for i = 1:N
%     mid1 = x(i);
    O(3*N + i) = x(i);
    O(4*N + i) = x(N+i);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sys = O;
% end mdlOutputs



%
%=============================================================================
% mdlGetTimeOfNextVarHit
% Return the time of the next hit for this block.  Note that the result is
% absolute time.  Note that this function is only used when you specify a
% variable discrete-time sample time [-2 0] in the sample time array in
% mdlInitializeSizes.
%=============================================================================
%
function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;    %  Example, set the next hit to be one second later.
sys = t + sampleTime;

% end mdlGetTimeOfNextVarHit

%
%=============================================================================
% mdlTerminate
% Perform any end of simulation tasks.
%=============================================================================
%
function sys=mdlTerminate(t,x,u)

sys = [];

% end mdlTerminate
