function S=sat(s) %���ͺ���

    if abs(s)<=1
        S=s;
    else
        S=sign(s);
    end
end