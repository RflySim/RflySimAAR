function [S,N,St,Nt,s] = FtrExtr4qm_1(Pic)

% I= imresize(Pic,scale,'nearest');
% Inew=rgb2gray(I);
s=size(Inew);
Iin=zeros(s(1),s(2));
for i=1:s(1)
    for j=1:s(2)
       if Inew(i,j)<50
%        if I(i,j,1)>0.16&I(i,j,1)<0.92|I(i,j,2)<0.16
            Iin(i,j)=0;
        else
            Iin(i,j)=1;
        end
    end
end


Iin=Pic(:,:,1)*2-Pic(:,:,2)*1-Pic(:,:,3)*1;

[L N]=bwlabel(Iin,8);
S=zeros(N,2);
[r1 c1]=find(Iin == 1);
Nt=max(size(r1));
St(:,1)=r1;
St(:,2)=c1;
 for k=1:N
     [r c]=find(L == k);
     S(k,1)=mean(r);
     S(k,2)=mean(c);
     i=floor(S(k,1));
     j=floor(S(k,2));
%      t=2;
%      I(i-t:i+t,j-t:j+t,1)=repmat(x(1),2*t+1,2*t+1);
%      I(i-t:i+t,j-t:j+t,2)=repmat(x(2),2*t+1,2*t+1);
%      I(i-t:i+t,j-t:j+t,3)=repmat(x(3),2*t+1,2*t+1);
 end
%  imshow(I)
end

