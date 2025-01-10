%% 按照《F-16受油机模型化简3》和《F16线性模型参数》得到的F16模型
% 非常重要：系统里输出长度单位是英尺，角度单位是弧度，输入舵偏是度
%% 基本参数      
p_r = [6.06;0.54;-0.86]; % 这个是锥管前端距质心的距离
% c_r = [6.06 0 ]; % 斥力模型中心距质心的距离
v0 = 120;

% x0_r_t = -12;
% z0_r_t = 0.86; % 起始位置
x0_r_t = -6.06; 
y0_r_t = -1;
z0_r_t = 1; % 起始位置

%% 受油机 %%

%%%% 纵向 %%%%% ---------------------------------------------------------------------------------
%              01.x , 02.h ,       03.theta ,   04.Vt ,         05.alpha ,      06.q 
A_rc_long_O = [0      0            -2.55e-09	1               0               0;
               0      0            393.72       0               -393.72         0;
               0      0            0            0               0               1;
               0      0.000111135  -32.17       -0.018054928	-8.065022573	-1.846855155;
               0      2.52e-06	   3.76e-15	    -0.000409721	-0.667371723	0.927561102;
               0      7.98e-12	   0            -1.30e-09       -0.742601       -0.850870526];
B_rc_long_O = [0              0   % 油门 升降舵
               0              0
               0              0
               0.001559526	  0.000437475
               -4.60e-07      -0.001426346
               0              -0.086580984];
C_rc_long_O = [1	0   0	0	0	0
               0	1	0	0	0	0
               0    0   1   0   0   0
               0    0   0   1   0   0];    
Cv_long = [0 0 0 1 0 0];

B_rc_long_O_ = B_rc_long_O;
B_rc_long_O_(:,1) = B_rc_long_O(:,1)*1000;    % 调整油门的输入，使其与升降舵在同一数量级

% n_rc_long = size(A_rc_long_O,1);

% 纵向四阶模型LQR的取得 %
% 内环增稳
% A4_long = A_rc_long_O(3:6,3:6);
% B4_long = B_rc_long_O_(3:6,:);
% Q4_long = diag([15 15 5 5]);
% R4_long = diag([5 5]);
% [k4_long,p4_long,e4_long]=lqr(A4_long,B4_long,Q4_long,R4_long);
% Kp_long_O = [zeros(2,2),k4_long];
% eig(A4_long - B4_long*k4_long)
%
% 全系统增稳
% Q_long = diag([30 30 15 30 5 5]);
% R_long = diag([5 5]);
% [k_long,p_long,e_long]=lqr(A_rc_long_O,B_rc_long_O_,Q_long,R_long);
% Kp_long_O = k_long;
% 
% eig(A_rc_long_O - B_rc_long_O_*k_long)
%%%%%%%%%%%%%%%%%%%%%%%%

Kp_long_O = [2.4349    0.2668   53.4474    3.0008  -63.2722    0.1787;
             0.2668   -2.4340 -886.7010    0.2458  667.9862  -77.6272];
%%%%% -------------------------------------------------------------------------------------------
         
%%%% 横侧向 %%%% ---------------------------------------------------------------------------------
%           01.y ,  02.psi ,  03.phi , 04.beta ,    05.p ,    06.r 
A_rc_lat_O = [ 0  393.7200  -45.4165  393.7200         0         0 ;
               0         0         0         0         0    1.0067 ;
               0         0         0         0    1.0000    0.1161 ;
               0         0    0.0812   -0.1726    0.1163   -0.9874 ;
               0         0         0  -17.7062   -2.0116    0.6735 ;
               0         0         0    3.5422   -0.0517   -0.2865 ];
B_rc_lat_O = [ 0         0    % 输入 副翼 方向舵
               0         0
               0         0
               0.0002    0.0005
               -0.3043   0.0583
               -0.0126   -0.0293];
C_rc_lat_O = [ 1	0   0	0	0	0
               0	1	0	0	0	0
               0    0   1   0   0   0
               0    0   0   1   0   0];
           
% n_rc_lat = size(A_rc_lat_O,1);
           
% 横侧向四阶模型LQR的取得 %
% 内环增稳
% A4_lat = A_rc_lat_O(3:6,3:6);
% B4_lat = B_rc_lat_O(3:6,:);
% Q4_lat = diag([15 15 5 5]);
% R4_lat = diag([5 5]);
% [k4_lat,p4_lat,e4_lat]=lqr(A4_lat,B4_lat,Q4_lat,R4_lat);
% Kp_lat_O = [zeros(2,2),k4_lat];
% eig(A4_lat - B4_lon*k4_lat)
%
% 全系统增稳
% Q_lat = diag([30 15 15 15 5 5]);
% R_lat = diag([5 5]);
% [k_lat,p_lat,e_lat]=lqr(A_rc_lat_O,B_rc_lat_O,Q_lat,R_lat);
% Kp_lat_O = k_lat;
% eig(A_rc_lat_O - B_rc_lat_O*k_lat)
%%%%%%%%%%%%%%%%%%%%%%%%

Kp_lat_O = [-2.4334   -1235.6   81.670    -1103.7   -11.020   -64.389;
             0.2801   -33.670  -3.4425    -20.635   -1.7260   -13.587];
%%%%% -------------------------------------------------------------------------------------------
      
%%%% 系统坐标变换，把长度单位统一成米，x h->z y,角度角速度等不变------------------------------------
%%jr%% 矩阵的单位变化和状态是一个相反的关系，状态是要直接乘以0.3048
Kunit_long = diag([1/0.3048 -1/0.3048 1 1/0.3048 1 1]); % x,h,theta,Vt,alpha,q 
Kunit_lat = diag([1/0.3048 1 1 1 1 1]);                 % y,psi,phi,beta,p,r 
A_long = Kunit_long\A_rc_long_O*Kunit_long;
B_long_ = Kunit_long\B_rc_long_O_;
A_lat = Kunit_lat\A_rc_lat_O*Kunit_lat;
B_lat = Kunit_lat\B_rc_lat_O;
Kp_long = Kp_long_O*Kunit_long;
Kp_lat = Kp_lat_O*Kunit_lat;
%%%%% -------------------------------------------------------------------------------------------

%%%% LQR之后的系统 %%%%---------------------------------------------------------------------------
A_long_k = A_long - B_long_*Kp_long; % 通过极点验证与配置后的系统基本一致，此时系统为A_k,B_,C
A_lat_k = A_lat - B_lat*Kp_lat;
%%%%% -------------------------------------------------------------------------------------------

%%%% 整理完整的线性模型 %%%-----------------------------------------------------------------------
Arc = [A_long_k,zeros(6,6);
       zeros(6,6),A_lat_k];
Brc = [B_long_(:,1),zeros(6,1),B_long_(:,2),zeros(6,1);
       zeros(6,1),  B_lat(:,1),zeros(6,1),  B_lat(:,2)];  % 注意输入调整为 T a e，这是为了与xyz相对应
Crc = [1 0 0 0 0 0 0 0 0 0 0 0;  % 输出xyzv
       0 0 0 0 0 0 1 0 0 0 0 0;
       0 1 0 0 0 0 0 0 0 0 0 0;
       0 0 0 1 0 0 0 0 0 0 0 0];
Drc = zeros(4,4);

%% 锥套模型，按BW那篇文章，进行了简单的简化
Ndr_xx = 0.002185;
Ddr_xx = [1 0.3071 2.682];
Ndr_xz = 0.006169;
Ddr_xz = [1 0.3013 2.689];
Ndr_yy = 0.01712;
Ddr_yy = [1 0.2422 2.081];
Ndr_zx = 0.005824;
Ddr_zx = [1 0.3223 2.687];
Ndr_zz = 0.01782;
Ddr_zz = [1 0.3391 2.687];

[Adrxx,Bdrxx,Cdrxx,Ddrxx] = tf2ss(Ndr_xx,Ddr_xx);
[Adrxz,Bdrxz,Cdrxz,Ddrxz] = tf2ss(Ndr_xz,Ddr_xz);
[Adryy,Bdryy,Cdryy,Ddryy] = tf2ss(Ndr_yy,Ddr_yy);
[Adrzx,Bdrzx,Cdrzx,Ddrzx] = tf2ss(Ndr_zx,Ddr_zx);
[Adrzz,Bdrzz,Cdrzz,Ddrzz] = tf2ss(Ndr_zz,Ddr_zz);

Adr = [Adrxx,     zeros(2,2),zeros(2,2),zeros(2,2),zeros(2,2);
       zeros(2,2),Adrzx,     zeros(2,2),zeros(2,2),zeros(2,2);
       zeros(2,2),zeros(2,2),Adryy,     zeros(2,2),zeros(2,2);
       zeros(2,2),zeros(2,2),zeros(2,2),Adrxz,     zeros(2,2);
       zeros(2,2),zeros(2,2),zeros(2,2),zeros(2,2),Adrzz];
Bdr = [Bdrxx,     zeros(2,1),zeros(2,1);
       Bdrzx,     zeros(2,1),zeros(2,1);
       zeros(2,1),Bdryy,     zeros(2,1);
       zeros(2,1),zeros(2,1),Bdrxz;
       zeros(2,1),zeros(2,1),Bdrzz;];
Cdr = [Cdrxx,     zeros(1,2),zeros(1,2),Cdrxz,     zeros(1,2);
       zeros(1,2),zeros(1,2),Cdryy,     zeros(1,2),zeros(1,2);
       zeros(1,2),Cdrzx,     zeros(1,2),zeros(1,2),Cdrzz];
Ddr = zeros(3,3); % 通过TEST3验证与原锥套模型相近

%% 保存数据
save('longlatParameters.mat','A_rc_long_O','B_rc_long_O','C_rc_long_O','Kp_long_O',...
                             'A_rc_lat_O','B_rc_lat_O','C_rc_lat_O','Kp_lat_O',...
                             'Arc','Brc','Crc','Drc','Adr','Bdr','Cdr','Ddr',...
                             'x0_r_t','y0_r_t','z0_r_t','p_r','v0');