1. 运行 RflySim3D;
2. 打开 Simulink平台 文件夹中的AirRefueling_Platform_IBVS.slx(或者AirRefueling_Platform_IBVS.slx），在 Natural wind model模块 中设置紊流等级，点击运行按钮。
3. 当 RflySim3D 中出现仿真飞机时，点击暂停按钮，在 RflySim3D 窗口中按下 B 1 , 切换到受油机视角；
4. 运行 Python 视觉处理文件夹中的 detect-realtime.py , 当出现 RGB 图像和深度图像之后，切换到Simulink , 点击继续按钮；
5. 飞机自动进行对接，对接成功后自动松开；
6. 仿真后matlab工作区得到的数据变量命名为IBVSn1.mat, IBVSn2.mat, IBVScompare.mat, PBVS.mat保存在 仿真结果文件夹 中。（ IBVSn1.mat，IBVSn2.mat，IBVScompare.mat中包含d_pr_dr、E_imag、z_cd、t变量，IBVSn1.mat，IBVSn2.mat，IBVScompare.mat分别表示为IBVS在紊流强度10^-1,10^-2,和PBVS形成对比的仿真后的数据文件）（PBVS.mat中包含d_pr_dr、t变量，PBVS.mat表示PBVS仿真后的数据文件）
7. 打开 Simulink平台 文件夹中的 仿真结果文件夹中的Plot_IBVS.m文件，加载IBVSn1.mat文件，可得到Fig11.5, Fig11.6, 加载IBVSn2.mat文件，可得到Fig11.7, Fig11.8；
8. 在Plot_IBVS.m文件下，加载IBVScompare.mat文件，可得到Fig11.9左图；在Plot_PBVS.m文件下，加载PBVS.mat文件，可得到Fig11.9右图。
注:直接从步骤7进行，得到Fig11.5-11.9