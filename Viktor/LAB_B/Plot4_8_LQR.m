clear; close all;
load("4_8_LQR.mat","xw","thetab")
afFigurePosition = [1 1 10 6];
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')

   index = 1:2000;
figure
plot(xw.time(index),xw.signals.values(index,:))
title("$$x_w$$"); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("Simulator","Full order","Reduced order")
print('-depsc2', '-r300', 'LabB_4_8_xw_LQR.eps');

figure
plot(thetab.time(index),thetab.signals.values(index,:))
title("$$\theta_b$$"); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("Simulator","Full order","Reduced order")
print('-depsc2', '-r300', 'LabB_4_8_thetab_LQR.eps');