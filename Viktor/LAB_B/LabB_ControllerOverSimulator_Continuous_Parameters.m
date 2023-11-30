close all;
clear all;
clc;

load Linear_Param.mat

% % SS pole placement
% omegan = 5.7;
% zeta = 0.8;
% ideal_poles = [-475;
%                 -6*omegan*zeta;
%                 omegan*(-zeta+1i*sqrt(1-zeta^2));
%                 omegan*(-zeta-1i*sqrt(1-zeta^2))];
% K = acker(A,B(:,1),ideal_poles);


% % SS LQR design
Cweight = [5 1 10 2]; %Most weight on theta_b, then on x_w, least on velocities
B1 = B(:,1);
[num,den] = ss2tf(A,B1,Cweight,0);
s = tf("s");
Nplus = num(1)*(s)^4 +num(2)*(s)^3 +num(3)*(s)^2 +num(4)*(s)^1 +num(5)*(s)^0;
Nminus = num(1)*(-s)^4 +num(2)*(-s)^3 +num(3)*(-s)^2 +num(4)*(-s)^1 +num(5)*(-s)^0;
Dplus = den(1)*(s)^4 +den(2)*(s)^3 +den(3)*(s)^2 +den(4)*(s)^1 +den(5)*(s)^0;
Dminus = den(1)*(-s)^4 +den(2)*(-s)^3 +den(3)*(-s)^2 +den(4)*(-s)^1 +den(5)*(-s)^0;
sysGG = Nplus*Nminus/(Dplus*Dminus);
% rho = linspace(0,10);
% rlocus(sysGG,rho)

rhoChose = 3.5;
  % pzmap(1+rhoChose*sysGG)
poles =  zero(1+rhoChose*sysGG);
stablePoles = poles(real(poles)<0);
K = acker(A,B1,stablePoles);
<<<<<<< HEAD

%LQR seems to perform better, also "easier" to design
=======
>>>>>>> 95abb65cc366284d8a3a7f53c7aafc9476e64063
