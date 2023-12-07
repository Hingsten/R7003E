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
plot(thetab.time(index),thetab.signals.values(index,:)*180/pi)
title("$$\theta_b$$"); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("Simulator","Full order","Reduced order")
print('-depsc2', '-r300', 'LabB_4_8_thetab_LQR.eps');


figure
plot(thetab.time(index),abs(thetab.signals.values(index,1)-thetab.signals.values(index,2))*180/pi)
hold on
plot(thetab.time(index),abs(thetab.signals.values(index,1)-thetab.signals.values(index,3))*180/pi)
hold off
title("$$\theta_b$$"); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("Full order","Reduced order")
print('-depsc2', '-r300', 'LabB_4_8_thetab_ABSDIFF_LQR.eps');


figure
plot(xw.time(index),abs(xw.signals.values(index,1)-xw.signals.values(index,2)))
hold on
plot(xw.time(index),abs(xw.signals.values(index,1)-xw.signals.values(index,3)))
hold off
title("$$x_w$$"); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
legend("Full order","Reduced order")
print('-depsc2', '-r300', 'LabB_4_8_xw_ABSDIFF_LQR.eps');

format short
maxFullThetaDiff = max(abs(thetab.signals.values(index,1)-thetab.signals.values(index,2))*180/pi)
maxReducedThetaDiff =max(abs(thetab.signals.values(index,1)-thetab.signals.values(index,3))*180/pi)
maxFullXdiff = max(abs(xw.signals.values(index,1)-xw.signals.values(index,2)))
maxReducedXDiff = max(abs(xw.signals.values(index,1)-xw.signals.values(index,3)))