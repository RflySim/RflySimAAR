%%״̬����h,theta,v,alpha,q,el �Ƕȵ�λΪ���ȣ����ȵ�λΪft�����ŵ�λΪlbs
A=[0	393.72	0	-393.72	0	0
0	0	0	0	1	0
0.000111135	-32.17	-0.018054928	-8.065022573	-1.846855155	0.000437475
2.52E-06	3.76E-15	-0.000409721	-0.667371723	0.927561102	-0.001426346
7.98E-12	0	-1.30E-09	-0.742601	-0.850870526	-0.086580984
0	0	0	0	0	-20.2

];

%%�������ζ�Ӧ���ź�������
%Ϊ�˷�����켣��ƣ��ԣ½�����ȡ����
B=[0
0
0
0
0
-20.2
];

C_q=[0 0 0  0 57.29577951 0];
C_theta=[0 57.29577951 0 0 0 0];
C_h=[0.3048 0 0 0 0 0];


C=[C_q;C_theta;C_h];
D=[0;
   0;
   0];

plant_actual=ss(A,B,C,D);

[a,b,c,d]=ssdata(plant_actual);
%rlocus(a,b,c(1,:),0)

k_q=2;
ac1=a-b*[k_q 0 0]*c;
sysqClosed=ss(ac1,b,c(2:3,:),d(2:3));


[a,b,c,d]=ssdata(sysqClosed);
%[z,p,k]=ss2zp(a,b,c(1,:),0)
%rlocus(a,b,c(1,:),0)
k_theta=1.9;
ac1=a-b*[k_theta 0]*c;
sysThetaClosed=ss(ac1,k_theta*b,c(2,:),d(2));

[a,b,c,d]=ssdata(sysThetaClosed);

[z,p,k]=ss2zp(a,b,c,d)

margin(a,b,c,d)
%figure
%[z,p,k]=ss2zp(a,b,c,d)
%rlocus(ac1,b,c(2,:),0)
