load 4_8.mat
afFigurePosition = [1 1 10 6];
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')

figure(1)
plot(xw)
title('$$x_w$$'); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("LQR","Pole placement")
print('-depsc2', '-r300', 'LabB_4_8_xw_PID.eps');

figure(2)
plot(thetab)
title('$$\theta_b$$'); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("LQR","Pole placement")
print('-depsc2', '-r300', 'LabB_4_8_thetab_PID.eps');