close all;
clear all;
clc;

load Linear_Param.mat
omegan = 5.7;
zeta = 0.8;
ideal_poles = [-475;
                -6*omegan*zeta;
                omegan*(-zeta+1i*sqrt(1-zeta^2));
                omegan*(-zeta-1i*sqrt(1-zeta^2))];
K = acker(A,B(:,1),ideal_poles);

