close all; clear all;
disturbance  = 0.8; %newton
d = 0.8/0.02;
save("LABA_CONT.mat","d","-append")
open_system('./PlottingContvsSim.slx');
sim('./PlottingContvsSim.slx');
save_system('./PlottingContvsSim.slx');
close_system('./PlottingContvsSim.slx');
afFigurePosition = [1 1 10 6];
figure(1)
plot(x_w.time, x_w.signals.values);
title('x_w'); xlabel('time'); ylabel('meters')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_CONT_VS_x_w.eps');
figure(2)
plot(theta_b.time, theta_b.signals.values * 180 / pi);

title('\theta_b'); xlabel('time'); ylabel('degrees')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_CONT_VS_theta_b.eps');
figure(3)
plot(d.time, d.signals.values);
title('d'); xlabel('time'); ylabel('Newton')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_CONT_VS_d.eps');
figure(4)
plot(v_m.time, v_m.signals.values);
title('v_m'); xlabel('time'); ylabel('Volt')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_CONT_VS_v_m.eps')