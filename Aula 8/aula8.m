clc; close all; clear all

num = [0.0022];
den = [1 -0.2403];
T = 0.1;
G = tf(num,den,0.1)
pidTuner(G)

% Kp = 38.98
% Ki = 779.6