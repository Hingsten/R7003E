load discreteStateSpace.mat
Bweight = [0 0 1 0]';
model = ss(Ad,Bweight,Cd,0);
[num, den] = ss2tf(Ad,Bweight,Cd,[0;0])