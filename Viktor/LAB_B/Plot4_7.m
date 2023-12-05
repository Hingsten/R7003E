load 4_7_1.mat
afFigurePosition = [1 1 10 6];
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')

figure(1)
index = 1:5000;
plot(x.time(index), x.signals.values(index,1));
title('$$x_w$$'); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
% legend("Simulation","Linearized Plant")
print('-depsc2', '-r300', 'LabB_4_7_xw.eps');

figure(2)
plot(x.time(index), x.signals.values(index,3) * 180 / pi);
title('$$\theta_b$$'); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
% legend("Simulation","Linearized Plant")
print('-depsc2', '-r300', 'LabB_4_7_thetab.eps');