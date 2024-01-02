% close all;
clear all;

set(0,'defaulttextinterpreter','latex')
  set(0,'DefaultTextFontname', 'CMU Serif')
   set(0,'DefaultAxesFontName', 'CMU Serif')
afFigurePosition = [1 1 10 6];

% load 5_5_Sine_200_Hz.mat
% fileName = "Sine_200_Hz";

% load 5_5_200cm_10s.mat
% fileName = "200cm_10s";
% 
% load 5_5_50cm_10s.mat
% fileName = "50cm_10s";

% load 5_4_40_Hz.mat
% fileName = "100_Hz";

% index = 1000:5000;
% index = 1000:1100
% 
% figure
% t = [0 10 20 30];
% r = [0 0 0.5 0.5];
% plot(t,r)
% xlabel('time [sec]');
% ylabel('position [m]');
% title('$$x_w$$');
% set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
% 
% print('-depsc2', '-r300', "Labc_5_5_reference_50cm");


% figure
% t = [10 18 28 30];
% r = [0 0 2 2];
% plot(t,r)
% xlabel('time [sec]');
% ylabel('position [m]');
% title('$$x_w$$');
% set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');
% 
% print('-depsc2', '-r300', "Labc_5_5_reference_200cm");

figure
t = linspace(10,40);
r = 0.15*sin(2*pi*0.2*t);
plot(t,r)
xlabel('time [sec]');
ylabel('position [m]');
title('$$x_w$$');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition); set(gcf, 'PaperPositionMode', 'auto');

print('-depsc2', '-r300', "Labc_5_5_reference_sin");



