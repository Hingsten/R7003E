load("symbolicStateSpace.mat")
syms b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t g
gv = 9.8;
b_fv = 0;
m_bv = 0.381;
l_bv = 0.112;
I_bv = 0.00616;
m_wv = 0.036;
l_wv = 0.021;
I_wv = 0.00000746;
R_mv = 4.4;
L_mv = 0;
b_mv = 0;
K_ev = 0.444;
K_tv = 0.470;
% subs(A,[I_b l_w])
Anumerical = vpa(subs(A,[b_f, m_b, l_b, I_b, m_w, l_w, I_w, R_m, L_m, b_m, K_e, K_t,g],[b_fv m_bv l_bv I_bv m_wv l_wv I_wv R_mv L_mv b_mv K_ev K_tv gv]),4);
Bnumerical = vpa(subs(B,[b_f, m_b, l_b, I_b, m_w, l_w, I_w, R_m, L_m, b_m, K_e, K_t,g],[b_fv m_bv l_bv I_bv m_wv l_wv I_wv R_mv L_mv b_mv K_ev K_tv gv]),4);
A = double(Anumerical)
B = double(Bnumerical)
C = [0 0 1 0];
D = 0;
save(currentfolder+"\Viktor\Lab_A\LABA_CONT.mat","A","B","C","D","-append")