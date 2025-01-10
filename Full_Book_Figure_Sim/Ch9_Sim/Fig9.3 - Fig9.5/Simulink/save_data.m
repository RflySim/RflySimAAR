P_lnk_HDU = reshape(P_lnk_HDU, 60, 10001);
P_lnk_HDU = transpose(P_lnk_HDU);

P_lnk_nHDU = reshape(P_lnk_nHDU, 60, 10001);
P_lnk_nHDU = transpose(P_lnk_nHDU);

P_drg_HDU2 = P_drg_HDU;
P_drg_nHDU2 = P_drg_nHDU;
P_lnk_nHDU2 = P_lnk_nHDU;
P_prb_HDU2 = P_prb_HDU;
P_prb_nHDU2 = P_prb_nHDU;
P_lnk_HDU2 = P_lnk_HDU;

save('data.mat', "P_drg_HDU2", "P_drg_nHDU2", "P_lnk_nHDU2", ...
    "P_prb_HDU2", "P_prb_nHDU2", "P_lnk_HDU2");
