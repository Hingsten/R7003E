close all; clear all;
load IMPROVED_LQR_NUMRICAL.mat % LOAD DATA
set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')
afFigurePosition = [1 1 10 6];

index = 1000:length(afTimes)-1000;
% index = 1000:2000;
figure
plot(afTimes(1:length(index)), aafProcessedInformation(MEASURED_X_W_INDEX,index));
xlabel('time [sec]');
ylabel('position [m]');
title('$$x_w$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
xaxis(0,max(afTimes(1:length(index))))
print('-depsc2', '-r300', 'LabB_4_10_x_w.eps');



figure
plot(afTimes(1:length(index)), aafProcessedInformation(MEASURED_THETA_B_INDEX,index)/pi*180);
xlabel('time [sec]');
ylabel('angle [degrees]');
title('$$\theta_b$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
xaxis(0,max(afTimes(1:length(index))))
print('-depsc2', '-r300', 'LabB_4_10_theta_b.eps');


figure
plot(afTimes(1:length(index)), aafProcessedInformation(1,index));
hold on
plot( [min(afTimes(1:length(index))), max(afTimes(1:length(index)))],[9 9],"r");
plot( [min(afTimes(1:length(index))), max(afTimes(1:length(index)))],[-9 -9],"r");
hold off
legend("Motor voltage","Saturation voltage")
xlabel('time [sec]');
ylabel('voltage [v]');
title('$$u$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
xaxis(0,max(afTimes(1:length(index))))
print('-depsc2', '-r300', 'LabB_4_10_u.eps');

