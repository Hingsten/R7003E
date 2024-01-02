% close all;
clear all;

set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')
afFigurePosition = [1 1 10 6];

% load 5_5_Sine_200_Hz.mat
% fileName = "Sine_200_Hz";

load 5_5_200cm_10s.mat
fileName = "200cm_10s";

% load 5_5_50cm_10s.mat
% fileName = "50cm_10s";

% load 5_4_40_Hz.mat
% fileName = "100_Hz";

% index = 1000:5000;
% index = 1000:1100
index = 2000:length(aafProcessedInformation);
figure
plot(afTimes(index), aafProcessedInformation(MEASURED_X_W_INDEX,index));
xlabel('time [sec]');
ylabel('position [m]');
title('$$x_w$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
namexw = sprintf("LabC_5_5_x_w_" + fileName);
print('-depsc2', '-r300', namexw);


figure
plot(afTimes(index), aafProcessedInformation(MEASURED_THETA_B_INDEX,index)*180/pi );
xlabel('time [sec]');
ylabel('angle [degrees]');
title('$$\theta_b$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
namethetab = sprintf("LabC_5_5_theta_b_" + fileName);
print('-depsc2', '-r300', namethetab);


figure
plot(afTimes(index), aafProcessedInformation(1,index));
xlabel('time [sec]');
ylabel('voltage [v]');
title('$$u$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
namevm = sprintf("LabC_5_5_v_m_" + fileName);
print('-depsc2', '-r300', namevm);
