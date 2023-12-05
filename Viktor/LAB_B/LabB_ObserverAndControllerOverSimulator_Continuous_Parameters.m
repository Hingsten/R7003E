close all;
clear all;
clc;

load Linear_Param.mat
load poles.mat
format shortE


%LQR -method
Cweight = [10 1 10 2]; %Most weight on theta_b, then on x_w, least on velocities
B1 = B(:,1);
[num,den] = ss2tf(A,B1,Cweight,0);
s = tf("s");
Nplus = num(1)*(s)^4 +num(2)*(s)^3 +num(3)*(s)^2 +num(4)*(s)^1 +num(5)*(s)^0;
Nminus = num(1)*(-s)^4 +num(2)*(-s)^3 +num(3)*(-s)^2 +num(4)*(-s)^1 +num(5)*(-s)^0;
Dplus = den(1)*(s)^4 +den(2)*(s)^3 +den(3)*(s)^2 +den(4)*(s)^1 +den(5)*(s)^0;
Dminus = den(1)*(-s)^4 +den(2)*(-s)^3 +den(3)*(-s)^2 +den(4)*(-s)^1 +den(5)*(-s)^0;
sysGG = Nplus*Nminus/(Dplus*Dminus);
rhoChose = 8.5;
poles =  zero(1+rhoChose*sysGG);
stablePoles = poles(real(poles)<0);
K = acker(A,B1,stablePoles);
poles = stablePoles;

save("poles.mat","poles")

%Full order
factor = 4;
speed = max(abs(poles(2:4)));
contObserverPoles(1) = poles(1);
contObserverPoles(2) = -6*factor*speed; % Place pole to not disturb dominant poles
omegan = factor*speed;
zeta = 0.8;
contObserverPoles(3:4) =    [omegan*(-zeta+1i*sqrt(1-zeta^2));
                             omegan*(-zeta-1i*sqrt(1-zeta^2))];

C = [1 0 0 0;0 0 1 0];
L = (place(A',C',contObserverPoles))';


T = [C;0 1 0 0; 0 0 0 1];
An = inv(T)*A*T ;  %New A-matrix
Bn = inv(T)*B(:,1);     %New B-matrix
Cbacc = C(1,:)*T;  %Accurate
Cbnacc = C(2,:)*T; %Not accurate

Ayy = An(1,1); %Zero
Ayx = An(1,2:4);  %Noisy/unobserved states
Axy = An(2:4,1); % Zero
Axx = An(2:4,2:4); %Noisy/unobserved states

By = Bn(1);
Bx = Bn(2:4);

Cy = Cbnacc(1);
Cx = Cbnacc(2:4);

AA = Axx;
CC = [Ayx
      Cx];
Lpartial = ( place( AA', CC', contObserverPoles(2:4) ) )';
Lacc = Lpartial(:,1);
Lnacc = Lpartial(:,2);

poles(2:4);
observerPoles = eig(AA-Lpartial*CC);

M1 = Axx-Lacc*Ayx-Lnacc*Cx;
M2 = Bx-Lacc*By;
M3 = Axy-Lacc*Ayy-Lnacc*Cy;
M4 = Lnacc;
M5 = Lacc;
M6 = T(:,1);
M7 = T(:,2:4);

%Making sure that A, B, C and D are correct
B = B(:,1);
C = [1 0 0 0; 0 0 1 0];
D = [0 ;0];



% M1 = 1.0e+03 * [
%    -0.4358   -0.0072    0.0091
%    -0.0011   -0.0340    0.0010
%     1.8717   -0.0165   -0.0400
% ]
% 
% M2 = [
%    20.6000
%          0
%   -90.0000
% ]
% 
% M3 = [
%      0
%      0
%      0
% ]
% 
% M4 = [
%     1.1459
%    33.9942
%    78.4584
% ]
% 
% M5 = [
%     0.7598
%     1.1459
%    31.6987
% ]
% 
% M6 = [
%      1
%      0
%      0
%      0
% ]
% 
% M7 = [
%      0     0     0
%      1     0     0
%      0     1     0
%      0     0     1
% ]
% 
% L = [
%    15.0196    0.5900
%    -2.7287   18.9345
%     0.6038   44.9804
%    22.1715  435.4379
% ]
% 
% A = 1.0e+03 * [
%          0    0.0010         0         0
%          0   -0.4350   -0.0061    0.0091
%          0         0         0    0.0010
%          0    1.9034    0.0620   -0.0400
% ]
% 
% B = [
%          0
%    20.6000
%          0
%   -90.0000
% ]
% 
% C = [
%      1     0     0     0
%      0     0     1     0
% ]
% 
% D = [
%      0
% ]
% 
% K = [ -10.0000  -57.4908 -105.0371  -19.5009 ]


