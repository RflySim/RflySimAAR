1、TankerVortexWindField文件有修改，第6行airSpeed1由原来的120修改为了190；
     新平台新增controller_para.m文件
     F16_init.m文件中新增代码270-281行
     增加了画图文件
     仿真时间改为200s，步长设置为变步长，求解器选择ode45，相对容差改为1e-3，绝对容差改为auto，勾选自动缩放绝对容差，其他选项默认
     位置保持控制是没有头波干扰，Hose-drogue system里面头波效应的输出置0
     Tanker system中的输入Pos_rc2tx改为了From p_rec
2、尾涡干扰下的仿真有以下改动：
    1、Tanker system模块中相对受油机的尾涡乘以了系数0.3
    2、Natural wind model模块里输入单位为ft，因此将Dryden Wind Turbulence Model (Continuous (+q -r))模块单位由国际制改为英制（纠错）
    3、在尾涡干扰下风干扰置零
3、大气干扰下的仿真有以下改动：
    1、Tanker system模块中尾涡置0
 