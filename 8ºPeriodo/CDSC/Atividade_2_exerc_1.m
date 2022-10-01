% A = (1 + s*0) / (50*s^2 + 200*s + 1)
% B = (1 + s*0) / (5000*s^2 + 200*s + 1)

clear;
clc;
syms s;
close all;

numerador_Q1 = 1 + s*0;
denominador_Q1 = 120*s^2 + 23.5*s + 1;
numerador_H1 = 4 + s*0;
denominador_H1 = 120*s^2 + 23.5*s + 1;
numerador_H2 = 2.5 + s*0;
denominador_H2 = 7.5*s + 1;

numerador_Q1_Poly = sym2poly(numerador_Q1);
denominador_Q1_Poly = sym2poly(denominador_Q1);
numerador_H1_Poly = sym2poly(numerador_H1);
denominador_H1_Poly = sym2poly(denominador_H1);
numerador_H2_Poly = sym2poly(numerador_H2);
denominador_H2_Poly = sym2poly(denominador_H2);

disp("===================================================================");
disp("Funcao de transferencia de Q1/Q");
G_Q1 = tf(numerador_Q1_Poly,denominador_Q1_Poly)

disp("===================================================================");
disp("Funcao de transferencia de H1/Q");
G_H1 = tf(numerador_H1_Poly,denominador_H1_Poly)

disp("===================================================================");
disp("Funcao de transferencia de H2/Q");
G_H2 = tf(numerador_H2_Poly,denominador_H2_Poly)

disp("===================================================================");
disp("Polos e zeros de Q1/Q");
[r_q1, p_q1, k_q1] = residue(numerador_Q1_Poly, denominador_Q1_Poly)

disp("===================================================================");
disp("Polos e zeros de H1/Q");
[r_h1, p_h1, k_h1] = residue(numerador_H1_Poly, denominador_H1_Poly)

disp("===================================================================");
disp("Polos e zeros de H2/Q");
[r_h2, p_h2, k_h2] = residue(numerador_H2_Poly, denominador_H2_Poly)

disp("===================================================================");
fprintf("Versão fatorada de H1/Q\n\n");

k = 0;
for i = 1:size(r_h1,1)
    k = k + r_h1(i)/(s-p_h1(i));
end

pretty(k);

disp("===================================================================");
fprintf("Inversa de H1/Q\n\n");

pretty(ilaplace(numerador_H1/denominador_H1))

[y_H1, t_H1] = step(G_H1);

disp("===================================================================");
fprintf("Resposta a um degrau (1 m^3/s) de H1/Q\n\n");

figure(1)
plot(t_H1, y_H1, 'r-.')
hold on;


ylim([0 4.1])
grid on;

disp("===================================================================");
fprintf("Valor de regime\n\n");

firstTime = find(y_H1 >= 4 - 0.005);
regime_permanente = y_H1(firstTime(end))
plot(t_H1(firstTime), y_H1(firstTime), 'b');

legend({'H1 - Nivel do reservatorio 1', 'Reg - Valor em regime permanente'},'Location','southeast');

disp("===================================================================");
fprintf("Valores de resposta de Q1/Q\n");
figure(2);

subplot(3,1,1);
[y, t] = step(G_Q1);
plot(t, y);
hold on;
plot(t, heaviside(y));
legend({'Q1 - Resposta ao degrau', 'DEG - Degrau'},'Location','southeast');
hold off;

subplot(3,1,2);
[y, t] = impulse(G_Q1);
plot(t, y);
hold on;
impulses = (t==0)/25;
plot(t, impulses, 'r');
legend({'Q1 - Resposta ao degrau', 'IMP - Impulso'},'Location','southeast');

subplot(3,1,3);
t_sin = 1:0.01:50;
sin_input = sin(2*pi*t_sin*(1/2))*3;
values = lsim(G_Q1, sin_input, t_sin, [0, 0, 0]);
plot(t_sin, values);
hold on;
plot(t_sin, sin_input, 'b--');
legend({'Q1 - Resposta ao degrau', 'SIN - Onda senoidal'},'Location','southeast');

disp("===================================================================");
fprintf("Valores de resposta de H1/Q\n");
figure(3);

subplot(3,1,1);
[y, t] = step(G_H1);
plot(t, y);
hold on;
plot(t, heaviside(y));
legend({'H1 - Resposta ao degrau', 'DEG - Degrau'},'Location','southeast');
hold off;

subplot(3,1,2);
[y, t] = impulse(G_H1);
plot(t, y);
hold on;
impulses = (t==0)/25;
plot(t, impulses, 'r');
legend({'H1 - Resposta ao degrau', 'IMP - Impulso'},'Location','southeast');

subplot(3,1,3);
t_sin = 1:0.01:50;
sin_input = sin(2*pi*t_sin*(1/2))*3;
values = lsim(G_H1, sin_input, t_sin, [0, 0, 0]);
plot(t_sin, values);
hold on;
plot(t_sin, sin_input, 'b--');
legend({'H1 - Resposta ao degrau', 'SIN - Onda senoidal'},'Location','southeast');

disp("===================================================================");
fprintf("Valores de resposta de H2/Q\n");
figure(4);

subplot(3,1,1);
[y, t] = step(G_H2);
plot(t, y);
hold on;
plot(t, heaviside(y));
legend({'H2 - Resposta ao degrau', 'DEG - Degrau'},'Location','southeast');
hold off;

subplot(3,1,2);
[y, t] = impulse(G_H2);
plot(t, y);
hold on;
impulses = (t==0)/4;
plot(t, impulses, 'r');
legend({'H2 - Resposta ao degrau', 'IMP - Impulso'},'Location','southeast');

subplot(3,1,3);
t_sin = 1:0.01:50;
sin_input = sin(2*pi*t_sin*(1/2))*3;
values = lsim(G_H2, sin_input, t_sin, [0, 0, 0]);
plot(t_sin, values);
hold on;
plot(t_sin, sin_input, 'b--');
legend({'H2 - Resposta ao degrau', 'SIN - Onda senoidal'},'Location','southeast');