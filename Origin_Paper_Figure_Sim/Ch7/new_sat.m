function y = new_sat(u)
ep = 0.2;
uu = u / ep;
if abs(uu) <= 1
    y = uu;
else
    y = sign(uu);      
end