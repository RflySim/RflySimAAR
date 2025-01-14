clear;
clc;

t=0:0.01:100;
t=t';

load data.mat;

P_drg_HDU=[t,P_drg_HDU];
P_drg_nHDU=[t,P_drg_nHDU];
P_lnk_HDU=[t,P_lnk_HDU];
P_lnk_nHDU=[t,P_lnk_nHDU];
P_prb_HDU=[t,P_prb_HDU];
P_prb_nHDU=[t,P_prb_nHDU];

load data3.mat;
P_lnk_HDU3 = reshape(P_lnk_HDU3, 30, 10001);
P_lnk_HDU3 = transpose(P_lnk_HDU3);
P_lnk_HDU3=[t,P_lnk_HDU3];
P_lnk_nHDU3 = reshape(P_lnk_nHDU3, 30, 10001);
P_lnk_nHDU3 = transpose(P_lnk_nHDU3);
P_lnk_nHDU3=[t,P_lnk_nHDU3];
