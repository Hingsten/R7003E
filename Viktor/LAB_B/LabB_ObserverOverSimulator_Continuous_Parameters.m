close all;
clear all;
clc;


% load the PID! Ok...
kP = -58.0796;
kI = -360.7094;
kD = -0.1207;

load Linear_Param.mat
load poles.mat
format shortE
B1 = B(:,1);
K = acker(A,B1,poles)

%Full order
C = [1 0 0 0;0 0 1 0];
factor = 4;
speed = max(abs(poles(2:4)));
contObserverPoles(1) = poles(1);
contObserverPoles(2) = -2*factor*speed; % Place pole to not disturb dominant poles
omegan = factor*speed;
zeta = 0.99;
contObserverPoles(3:4) =    [omegan*(-zeta+1i*sqrt(1-zeta^2));
                             omegan*(-zeta-1i*sqrt(1-zeta^2))];
L = (place(A',C',contObserverPoles))'


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

%%Example code provided
% 
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
