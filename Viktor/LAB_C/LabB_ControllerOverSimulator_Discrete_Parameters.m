close all;
clear all;
clc;

% select the sampling time
fs = 5; %Hz
simStep = 0.001;
fSamplingPeriod = floor(1/fs/simStep)*simStep
[Ad,Bd,Cd,Dd] = getDiscreteStateSpace(fSamplingPeriod);

%Paramaters for dlqr

Cweight = [20 5 10 1];   
rho = 20;      
Kd = getDiscreteKd(Cweight,rho,fSamplingPeriod)


