% %I=imread('aa.jpg');
% clear
% clc
% 
% I=imread('aa.jpg'); 
% I=double(I);
% Ir=I(:,:,1)*2-I(:,:,2)*1-I(:,:,3)*1;  %这个可以自己再调整下，我用的是2*红-绿-蓝 
% Ir=medfilt2(Ir,[5,5]);%进行中值滤波;
% %imshow(Ir)
% 
% imshow(I(:,:,3));
% 
% %[Im,M]=max(Ir);
% %[Imm,N]=max(Im);
% %P_x=N;
% %P_y=M(N);


clear
I=imread('bb5.jpg');
Ir=I(:,:,1)*2-I(:,:,2)*1-I(:,:,3)*1;

%imshow(Ir)

s=size(Ir);
Iin=zeros(s(1),s(2));
for i=1:s(1)
    for j=1:s(2)
       if Ir(i,j)<50
            Iin(i,j)=0;
        else
            Iin(i,j)=1;
        end
    end
end

[L,N]=bwlabel(Iin,8);

S=zeros(N,2);
 for k=1:N
     [r,c]=find(L == k);
     S(k,1)=mean(r);
     S(k,2)=mean(c);
     
 end
%plot(S(:,1),S(:,2),'+')
% dx(:,1)=S(:,1)-mean(S(:,1));
% dy(:,1)=S(:,2)-mean(S(:,2));

dX=S(:,1);
dY=S(:,2);

m=[dX dY ones(size(dX))]\-(dX.^2+dY.^2);
cX=-0.5*m(1);
cY=-0.5*m(2);
cR=sqrt((m(1)^2+m(2)^2)/4-m(3));

alpha=0:pi/50:2*pi;
x=cR*cos(alpha)+cX;
y=cR*sin(alpha)+cY;

for k=1:length(alpha)

    i=floor(x(k));
    j=floor(y(k));
    Ir(i,j)=255;       
end

i=floor(cX);
j=floor(cY);
Ir(i-3:i+3,j)=255; 
Ir(i,j-3:j+3)=255; 

yI=[cX,cY,cR];

imshow(Ir)

% plot(x,y,'--w')
% 
% hold on
% %plot(S(:,1),S(:,2),'+')
% plot(cX,cY,'+');






%imshow(Iin)
% 
% I=imread('bb3.jpg');
% Ir=I(:,:,2)*2-I(:,:,1)*1-I(:,:,3)*1;
% figure
% imshow(Ir)

% rgb_g=rgb(:,:,2);
% rgb_b=rgb(:,:,3);
% zero=zeros(718,1279);
% R=cat(3,rgb_r,zero,zero);
% G=cat(3,zero,rgb_g,zero);
% B=cat(3,zero,zero,rgb_b);
% RGB=cat(3,rgb_r,rgb_g,rgb_b);
% subplot(2,2,1),imshow(R),title('红色分量');
% subplot(2,2,2),imshow(G),title('绿色分量');
% subplot(2,2,3),imshow(B),title('蓝色分量');
% subplot(2,2,4),imshow(RGB);