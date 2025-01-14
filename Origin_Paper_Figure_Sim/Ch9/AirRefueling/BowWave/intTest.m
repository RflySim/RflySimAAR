function m=intTest(z,x,y)
ztk=0;  
%
%  m=(0.056*z+0.024)*(1-0.0749998832206802*z)/((-1-z)^2+(-1-0.0749998832206802*z)^2);

[p,q]=size(z);
m=zeros(size(z));
for i=1:p
    for j=1:q
        m(i,j)=(0.09*z(i,j)+0.03)*(y-ztk*z(i,j))/((x-z(i,j))^2+(y-ztk*z(i,j))^2);
    end
end
end