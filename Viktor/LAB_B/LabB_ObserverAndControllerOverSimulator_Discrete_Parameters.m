close all;
clear all;
clc;

% select the sampling time
fSamplingPeriod = 0.005;

load Linear_Param.mat
load poles.mat
A;
B = B(:,1);
C = [1 0 0 0;
    0 0 1 0];
D = 0;
contStateSpace = ss(A,B,C,D);

discreteStateSpace = c2d(contStateSpace,fSamplingPeriod);
Ad = discreteStateSpace.A;
Bd = discreteStateSpace.B;
Cd = discreteStateSpace.C;
D = discreteStateSpace.D;
discretePoles = exp(poles*fSamplingPeriod);

%Controller
Kd = acker(Ad,Bd,discretePoles);

%Observers
factor = 4;
speed = max(abs(poles(2:4)));
contObserverPoles(1) = poles(1);
contObserverPoles(2) = -6*factor*speed; % Place pole to not disturb dominant poles

omegan = factor*speed;
zeta = 0.8;
contObserverPoles(3:4) =    [omegan*(-zeta+1i*sqrt(1-zeta^2));
                omegan*(-zeta-1i*sqrt(1-zeta^2))];
desiredPoles = exp(contObserverPoles*factor*fSamplingPeriod);

%Full order
Ld = (place(Ad',Cd',desiredPoles))';

%Reduced order
T = [C;0 1 0 0; 0 0 0 1];
An = inv(T)*Ad*T ;  %New A-matrix
Bn = inv(T)*Bd;     %New B-matrix
Cbacc = Cd(1,:)*T;  %Accurate
Cbnacc = Cd(2,:)*T; %Not accurate

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
Lpartial = ( place( AA', CC', desiredPoles(2:4) ) )';
Lacc = Lpartial(:,1);
Lnacc = Lpartial(:,2);

poles(2:4);
observerPoles = eig(AA-Lpartial*CC);

Md1 = Axx-Lacc*Ayx-Lnacc*Cx;
Md2 = Bx-Lacc*By;
Md3 = Axy-Lacc*Ayy-Lnacc*Cy;
Md4 = Lnacc;
Md5 = Lacc;
Md6 = T(:,1);
Md7 = T(:,2:4);
