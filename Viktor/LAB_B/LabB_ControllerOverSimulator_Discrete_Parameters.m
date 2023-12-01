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