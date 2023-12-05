load 4_7_1.mat
x1 = x;
load 4_6_1.mat
x2 = x;
afFigurePosition = [1 1 10 6];
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')

figure(1)
index = 1:2000;
plot(x1.time(index), x1.signals.values(index,1));
hold on
plot(x2.time(index), x2.signals.values(index,1));
hold off
title('$$x_w$$'); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("LQR","Pole placement")
print('-depsc2', '-r300', 'LabB_4_7_compare_xw.eps');

figure(2)
plot(x1.time(index), x1.signals.values(index,3) * 180 / pi);
hold on
plot(x2.time(index), x2.signals.values(index,3)*180/pi);
hold off
title('$$\theta_b$$'); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("LQR","Pole placement")
print('-depsc2', '-r300', 'LabB_4_7_compare_thetab.eps');