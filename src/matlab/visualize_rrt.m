clc
clear all
close all
axes('Units', 'normalized', 'Position', [0 0 1 1])
axis on

fprintf("This is a test MATLAB script!\n");
plot_space(10, 10, [3, 3], [7, 7])

function plot_space(w, h, s, e)
    axis([0, w, 0, h]);
    plot(w/4, h/4, '.');
    rectangle('Position', [1, 1, w/2, h/2]);
end
