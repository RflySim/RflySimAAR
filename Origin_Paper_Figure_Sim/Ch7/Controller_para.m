function [A_lon_define,B_lon_define,CC_lon,A_la_define,B_la_define,CC_la] = ...
Controller_para(A_define,B_define,Kp_define)
% ×ÝÏò
A_lon_define = A_define([1,3,5,7,8,11],[1,3,5,7,8,11]);
B_lon_define = B_define([1,3,5,7,8,11],1:2);
kp_lon = Kp_define(1:2,[1,3,5,7,8,11]);
A_lon_new = A_lon_define - B_lon_define * kp_lon;
P_lon = lyap(A_lon_new',diag([10,2,10,2,1,10]));
CC_lon = P_lon * B_lon_define;


%ºá²àÏò
A_la_define = A_define([2,4,6,9,10,12],[2,4,6,9,10,12]);
B_la_define = B_define([2,4,6,9,10,12],3:4);
kp_la = Kp_define(3:4,[2,4,6,9,10,12]);
A_la_new = A_la_define - B_la_define * kp_la;
P_la = lyap(A_la_new',diag([1,2,1,2,1,1]));
CC_la = P_la * B_la_define;

