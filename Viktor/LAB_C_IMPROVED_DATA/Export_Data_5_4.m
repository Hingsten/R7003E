close all; clear all;

set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')
afFigurePosition = [1 1 10 6];


hertz = [35;40;60;75;100;120;140;160;180;200];

indexStart = [1000 0].*ones(length(hertz),1);

for i = 1:length(hertz)
    fileName = sprintf("5_4_%i_Hz.mat",hertz(i));
    load(fileName) % LOAD DATA
    index = indexStart(i,1):length(afTimes)+indexStart(i,2);
    time = afTimes(1:length(index));
    xw = aafProcessedInformation(MEASURED_X_W_INDEX,index);
    thetab = aafProcessedInformation(MEASURED_THETA_B_INDEX,index)*180/pi; %Radians
    % L2thetab(i) = sqrt(sum(thetab.*conj(thetab))*fSamplingPeriod^2);
     L2thetab(i) = 1/length(thetab)*norm(thetab);
    % L2xw(i) = sqrt(sum(xw.*conj(xw))*fSamplingPeriod^2); 
    L2xw(i) = 1/length(xw)*norm(xw);
end
figure
 plot(hertz, L2xw)
xlabel('Sampling frequency[Hz]');
ylabel('$L^2$ norm[m]');
title('$$x_w$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabB_5_4_x_w_L2.eps');

figure
 plot(hertz, L2thetab)
xlabel('Sampling frequency[Hz]');
ylabel('$L^2$ norm[degrees]');
title('$\theta_b$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabB_5_4_theta_b_L2.eps');

% plot(time, xw)
% xlabel('time [sec]');
% ylabel('position [m]');
% title('$$x_w$$');
% set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
% xaxis(0,max(afTimes(1:length(index))))
% print('-depsc2', '-r300', 'LabB_4_10_x_w.eps');
% 
% 
% 
% figure
% plot(time, thetab);
% xlabel('time [sec]');
% ylabel('angle [degrees]');
% title('$$\theta_b$$');
% set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
% xaxis(0,max(afTimes(1:length(index))))
% print('-depsc2', '-r300', 'LabB_4_10_theta_b.eps');



