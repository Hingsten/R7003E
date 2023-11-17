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

beta = zeros(2,2);
beta(1,1) = K_t/R_m;
beta(1,2) = -l_w;
beta(2,1) = -K_t/R_m;
beta(2,2) = l_b;
Bb = gamma\beta;

A = zeros(4);
A(1,2) = 1;
A(2,:) = Ab(1,:);
A(3,4) = 1;
A(4,:) = Ab(2,:);

B = zeros(4,2);
B(2,:) = Bb(1,:);
B(4,:) = Bb(2,:);
A
B
C = eye(4);
D = zeros(4,2);
C
D

save("LABA_CONT.mat","A","B","C","D","-append")