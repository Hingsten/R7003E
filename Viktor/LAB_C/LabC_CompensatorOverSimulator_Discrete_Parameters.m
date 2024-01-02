clear all;
close all
clc
fs = 200;% Hz
simStep = 0.001;
fSamplingPeriod = floor(1/fs/simStep)*simStep
Cd = [1 0 0 0] %Consider only x_w
[Ad,Bd,~,Dd] = getDiscreteStateSpace(fSamplingPeriod);
Bd = Bd(:,1);

Cweight = [10, 1,10 ,2];
rho = 8.5;

% Cweight = [10, 2,20 ,1];
% rho = 20;
[Kd,CLP] = getDiscreteKd(Cweight,rho,fSamplingPeriod)

%Observer poles
factor = 4;
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
DCgain = [Cd zeros(size(Cd))]*inv(eye(8)-M)*[Bd;Bd]
Nud = inv(DCgain)
Nxd = 0;

[Ad,Bd,Cd,Dd] = getDiscreteStateSpace(fSamplingPeriod);
Bd = Bd(:,1);
Nud = 21 %Seems to be about right