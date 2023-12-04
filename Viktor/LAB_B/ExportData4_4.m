close all; clear all;
load PID_10_25.mat
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')
afFigurePosition = [1 1 10 6];

index = 2000:5500;
figure
plot(afTimes(index), aafProcessedInformation(MEASURED_X_W_INDEX,index));
xlabel('time [sec]');
ylabel('position [m]');
title('$$x_w$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabB_4_4_x_w.eps');


figure
plot(afTimes(index), aafProcessedInformation(MEASURED_THETA_B_INDEX,index));
xlabel('time [sec]');
ylabel('angle [rad]');
title('$$\theta_b$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabB_4_4_theta_b.eps');


figure
plot(afTimes(index), aafProcessedInformation(1,index));
xlabel('time [sec]');
ylabel('voltage [v]');
title('$$u$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabB_4_4_u.eps');

