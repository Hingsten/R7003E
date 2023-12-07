close all;
clear all;
clc;

% select the sampling time
fs = 4.5; %Hz
simStep = 0.001;
fSamplingPeriod = floor(1/fs/simStep)*simStep
[Ad,Bd,Cd,Dd] = getDiscreteStateSpace(fSamplingPeriod);

%Paramaters for dlqr

Cweight = [10 1 10 2];   %Our previous weighting vector, falls over for lower than 4.5 Hz
rho = 8.5;      
Kd = getDiscreteKd(Cweight,rho,fSamplingPeriod)


