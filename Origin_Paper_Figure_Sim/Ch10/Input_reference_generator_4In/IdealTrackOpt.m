function [ J ] = IdealTrackOpt( u )
%IDEALTRACKOPT Summary of this function goes here
%   Detailed explanation goes here

% Phi0_rc = evalin('base','Phi0_rc');
Phi_rc = evalin('base','Phi_rc');
Nend = evalin('base','Nend');
mrc = evalin('base','n_m_rc');
Ideal_x = evalin('base','Ideal_x');
Ideal_y = evalin('base','Ideal_y');
Ideal_z = evalin('base','Ideal_z');

y_x = Phi_rc(1:mrc:mrc*Nend,:)*u;
y_y = Phi_rc(2:mrc:mrc*Nend,:)*u;
y_z = Phi_rc(3:mrc:mrc*Nend,:)*u;

e_x = Ideal_x(2:Nend+1) - y_x;
e_y = Ideal_y(2:Nend+1) - y_y;
e_z = Ideal_z(2:Nend+1) - y_z;

Qx = abs(diag(Ideal_x(2:Nend+1)));
Qy = abs(diag(Ideal_y(2:Nend+1)));
Qz = abs(diag(Ideal_z(2:Nend+1)));

J = e_x'*Qx*e_x + e_y'*Qy*e_y + 10*e_z'*Qz*e_z;
end

