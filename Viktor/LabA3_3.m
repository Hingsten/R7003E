g = 9.8;
b_f = 0;
m_b = 0.381;
l_b = 0.112;
I_b = 0.00616;
m_w = 0.036;
l_w = 0.021;
I_w = 0.00000746;
R_m = 4.4;
L_m = 0;
b_m = 0;
K_e = 0.444;
K_t = 0.470;

gamma = zeros(2);
%
gamma(2,1) = m_b*l_b;
gamma(2,2) = I_b+m_b*l_b^2;
gamma(1,1) = l_w*(m_w+m_b)+I_w/l_w;
gamma(1,2) = l_b*l_w*m_b;

alfa = zeros(2,4);
alfa(2,2) = 1/l_w*(K_t*K_e/R_m+b_f);
alfa(2,3) = l_b*m_b*g;
alfa(2,4) = -1*(K_t*K_e/R_m+b_f);
alfa(1,2) = -alfa(2,2);
alfa(1,3) = 0;
alfa(1,4) = -alfa(2,4);

Ab = gamma\alfa;

beta = zeros(2,1);
beta(1,1) = K_t/R_m;
beta(2,1) = -K_t/R_m;
Bb = gamma\beta;

% x1 = xw
% x2 = dxw , dx1 = x2
% x3 = theta_b
% x4 = dtheta_b, dx3 = x4
A = zeros(4);
A(1,2) = 1;
A(2,:) = Ab(1,:);
A(3,4) = 1;
A(4,:) = Ab(2,:);

B = zeros(4,1);
B(2) = Bb(1);
B(4) = Bb(2);

format shortE
A;
B;
C = [ 0 0 1 0]; %theta_b;
D = 0;

syms s;
test = eye(4)*s ;
lest = test-A;
lest2 = vpa([lest(:,[1 2 4]) ,- B]);
rest = det(lest2);
lest3 = lest2(2:4,2:4);
rest2 = det(lest3);
lest4 = lest3([1,3],[1,3]);
rest3 = det(lest4);
lest4(2)*lest4(3);
subs(lest4(1),"s",0)*lest4(4) ;%practiaclly identical, but why is this?
% b2*a24 = b4*a22 ??? Yes or no? well
%

sys = ss(A,B,C,D);
Gfull = tf(sys)

%Correcting a little bit
S = tf("s");
K = B(4);
format long
poles = eig(A);

Gcorrected = K*S/(S-poles(2))/(S-poles(3))/(S-poles(4))

