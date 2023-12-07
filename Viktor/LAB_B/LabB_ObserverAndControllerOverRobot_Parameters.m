close all;
clear all;
clc;

% Do not modify these variables
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
% fGyroConversionFactor	= 250/32768;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');



% select the sampling time
fSamplingPeriod = 0.05;


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
Kd = place(Ad,Bd,discretePoles)

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


% %%Provided parameters
% Ld = [
% 	0.0723    0.0028
%     0.0015    0.0464
%     0.0030    0.2118
%     0.0399    2.1508
% ]
% 
% 
% Md1 = [
%     0.1066   -0.0417    0.0156
%    -0.0561    0.9865    0.0029
%     0.5176    0.0215    0.8387
% ]
% 
% Md2 = [
%     0.0355
%    -0.0048
%    -0.3641
% ]
% 
% Md3 = 1.0e+03 * [
%    -0.0288
%    -0.0316
%    -1.4370
% ]
% 
% Md4 = [
%     0.0331
%     0.0152
%     0.2480
% ]
% 
% Md5 = 1.0e+03 * [
%     0.0288
%     0.0316
%     1.4370
% ]
% 
% Md6 = [
%      1
%      0
%      0
%      0
% ]
% 
% Md7 = [
%      0     0     0
%      1     0     0
%      0     1     0
%      0     0     1
% ]
% 
% Ad = [ 
%     1.0000    0.0022   -0.0000    0.0001
%          0    0.1691   -0.0096    0.0173
%          0    0.0124    1.0006    0.0047
%          0    3.6345    0.2183    0.9237
% ]
% 
% Bd = [ 
%     0.0001
%     0.0394
%    -0.0006
%    -0.1715
% ]
% 
% Cd = [ 
%      1     0     0     0
%      0     0     1     0
% ]
% 
% Dd = [
%      0
%      0
% ]
% 
% Kd = [-8.1792  -49.1223  -71.4928  -11.5909]

%Test
% Q = zeros(4);
% Q(1,1) = 1/0.05^2;
% Q(2,2) = 0;
% Q(3,3) = 1/0.5^2
% Q(4,4) = Q(3,3)
% R = 1/8^2
% K = lqr(Ad,Bd,Q,R)
