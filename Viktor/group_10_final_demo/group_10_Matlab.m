
clear all;
close all
clc

iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= 250/32768;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');

fs = 200% Hz
fSamplingPeriod = 1/fs
Cd = [1 0 0 0] %Consider only x_w for reference tracking
[Ad,Bd,~,Dd] = getDiscreteStateSpace(fSamplingPeriod);
Bd = Bd(:,1);

%Controller
Cweight = [20, 5,10 ,1];
rho = 20;
[Kd,CLP] = getDiscreteKd(Cweight,rho,fSamplingPeriod);

%Observer poles
factor =6;
[~,slowPoleIndex] = min(abs(CLP)); %Find the slowest pole
index = 1:4;
index = setdiff(index,slowPoleIndex);
observerPoles(1) = CLP(slowPoleIndex);
observerPoles(2:4) = CLP(index).^factor; % Place pole to not disturb dominant poles
% observerPoles(4) = observerPoles(1);

%Full order
[Ld,resultingPoles] = getLd(observerPoles,fSamplingPeriod); 
%Partial order
[Md1,Md2,Md3,Md4,Md5,Md6,Md7] = getMd(observerPoles(2:4),fSamplingPeriod); 

%Now to calculate Nd
M = [Ad-Bd*Kd Bd*Kd; zeros(size(Ad))      Ad-Ld(:,1)*Cd];
DCgain = [Cd zeros(size(Cd))]*inv(eye(8)-M)*[Bd;zeros(size(Bd))]
Nud = inv(DCgain)
Nxd = 0;

[Ad,Bd,Cd,Dd] = getDiscreteStateSpace(fSamplingPeriod);
Bd = Bd(:,1);


function [Ad,Bd,Cd,Dd] = getDiscreteStateSpace(Ts)
%Continous state space values
A = [0,1,0,0;
    0,-435.034344762564,-6.09907530060445,9.13572124001803;
    0,0,0,1;
    0,1903.43949265033,62.0192858703667,-39.9722293457016];

B = [0,0;
    20.5759487387841,2.10539038415300;
    0,0;
    -90.0275435713120,2.02561904781032];
C = [1,0,0,0;
    0,0,1,0];
D = [0,0;0,0];


contStateSpace = ss(A,B,C,D);                   %Create state space model
discreteStateSpace = c2d(contStateSpace,Ts);    %Discretize it
Ad = discreteStateSpace.A;                      %Return output
Bd = discreteStateSpace.B;
Cd = discreteStateSpace.C;
Dd = discreteStateSpace.D;
end

function [Kd,CLP] = getDiscreteKd(Cweight,rho,Ts)
[Ad,Bd,~,~] = getDiscreteStateSpace(Ts);
%Paramaters for dlqr
R = 1;N=0; 
W = rho*(Cweight'*Cweight); %Corresponding weight matrix
[Kd,~,CLP] = dlqr(Ad,Bd(:,1),W,R); %Calculate gain and poles
end

function  [Ld,resultingPoles] = getLd(observerPoles,Ts)
[Ad,~,Cd,~] = getDiscreteStateSpace(Ts);
Ld = (place(Ad',Cd',observerPoles))';
resultingPoles = eig(Ad-Ld*Cd);
end

function [M1d,M2d,M3d,M4d,M5d,M6d,M7d] = getMd(reducedObserverPoles,Ts)
[Ad,Bd,Cd,Dd] = getDiscreteStateSpace(Ts);
T = inv([Cd;0 1 0 0; 0 0 0 1]);
An = inv(T)*Ad*T ;  %New A-matrix
Bn = inv(T)*Bd(:,1);     %New B-matrix
Cbacc = Cd(1,:)*T;  %Accurate
Cbnacc = Cd(2,:)*T; %Not accurate

Ayy = An(1,1); %Zero
Ayx = An(1,2:4);  %Noisy/unobserved states
Axy = An(2:4,1);% Zero
Axx = An(2:4,2:4); %Noisy/unobserved states

By = Bn(1);
Bx = Bn(2:4);

Cy = Cbnacc(1);
Cx = Cbnacc(2:4);

AA = Axx;
CC = [Ayx
      Cx];
Lpartial = ( place( AA', CC', reducedObserverPoles) )';
Lacc = Lpartial(:,1);
Lnacc = Lpartial(:,2);

M1d = Axx-Lacc*Ayx-Lnacc*Cx;
M2d = Bx-Lacc*By;
M3d = Axy-Lacc*Ayy-Lnacc*Cy;
M4d = Lnacc;
M5d = Lacc;
M6d = T(:,1);
M7d = T(:,2:4);
end