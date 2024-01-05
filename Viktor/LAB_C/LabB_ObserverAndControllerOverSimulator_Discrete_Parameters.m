close all;
clear all;
clc
fs = 13;% Hz
simStep = 0.0001;
fSamplingPeriod = floor(1/fs/simStep)*simStep
[Ad, Bd,Cd,Dd] = getDiscreteStateSpace(fSamplingPeriod);
Bd = Bd(:,1);

%Controller
Cweight = [20 5 10 1];
rho = 20;
[Kd,CLP] = getDiscreteKd(Cweight,rho,fSamplingPeriod);
Kd

%Observer poles
factor = 4;
[~,slowPoleIndex] = min(abs(CLP)); %Find the slowest pole
index = 1:4;
index = setdiff(index,slowPoleIndex);
observerPoles(1) = CLP(slowPoleIndex);
observerPoles(2:4) = CLP(index).^factor % Place pole to not disturb dominant poles
% observerPoles(4) = observerPoles(1);
% 
% speed = max(abs(real(CLP)))^factor;
% observerPoles(2) = speed^6; % Place pole to not disturb dominant poles
% theta = 4;
% observerPoles(3) = speed*(1+1i*tand(theta))
% observerPoles(4) = conj(observerPoles(3))
% index = 2:4;


%Full observer
[Ld,resultingPoles] = getLd(observerPoles,fSamplingPeriod); %Around 13 Hz
%Reduced observer
[Md1,Md2,Md3,Md4,Md5,Md6,Md7] = getMd(observerPoles(2:4),fSamplingPeriod); % No lower than 6 Hz
Nud = 0;
Nxd = 0;