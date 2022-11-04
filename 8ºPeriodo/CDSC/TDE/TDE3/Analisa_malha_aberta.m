close all;
clear;
clc;

num = 15;
den = [6000 1100 60 1];

out = sim("Malha_aberta_2016.slx");

% Dados da simulação
t = out.tout;
val = out.ma;

% Reproduzindo o gráfico
figure(1);
%plot(t, val);
hold on;

syms s;
transfer = tf(num,[den 0]);
[NUM, DEN] = tfdata(transfer);
func = poly2sym(cell2mat(NUM),s)/poly2sym(cell2mat(DEN),s);
f_t = ilaplace(func);
f_t_h = matlabFunction(f_t);
d_1 = diff(f_t);
d_1_h = matlabFunction(d_1);
d_2 = diff(d_1);
d_2_h = matlabFunction(d_2);
x_sample = fzero(d_2_h, 75);
a = d_1_h(x_sample);
y = f_t_h(round(x_sample));
b = y-a*x_sample;

lin = @(x) a*x + b;

% Cálculo do valor e tempo de estabilidade
stable = val(end);
% ts = index do tempo (não é o tempo em si)
ts = t(find(val < (0.98*stable) | val > (1.02*stable), 1, 'last'));

% Gerando a reta inteira
res = lin(t);
x_ft = f_t_h(t);
plot(t, x_ft);
hold on;
% Encontrando os parâmetros limites (tempo máximo e mínimo)
linear_stable = find(res > stable , 1, 'first');
linear_start = find(res >= 0, 1 ,'first');

% Plotando a reta limitada nos pontos que queremos
plot(t(linear_start:linear_stable,1), res(linear_start:linear_stable,1));

% Obtendo o ponto igual a 0 e o tempo na reta que fica igual pra igual com 
% o ponto de estabilidade
tal_start = roots([a b]);
tal_end = t(linear_stable);
tal = tal_end-tal_start;

% Calculo dos outros parâmetros de estabilidade 
T = tal_start;
K = ((stable-0)/(1-0));

% Visualização
fprintf("Tal: %f", tal);
fprintf("\nT: %f", T);
fprintf("\nK: %f", K);
fprintf("\nts: %f\n", ts);

% ==============================================
% ================= P, PI  e PID ===============

P_Kp = tal/(K*T);
PI_Kp = 0.9*tal/(K*T);
PI_Ti = T/0.3;
PID_Kp = 1.2*tal/(K*T);
PID_Ti = 2*T;
PID_Td = 0.5*T;

f = figure(2);
h = {'Kp', 'Ti', 'Td'};
data = [P_Kp inf 0; PI_Kp PI_Ti 0; PID_Kp PID_Ti PID_Td];
tabl = uitable(f, 'data', data, 'columnname', h);

out_pid = sim("Malha_aberta_PID_2016.slx");

% Gerando gráficos do comportamento dos controladores

fig = figure(3);
subplot(3,1,1);
plot(out.tout ,out_pid.p);
title("Controlador P");
subplot(3,1,2);
plot(out.tout ,out_pid.pi);
title("Controlador PI");
subplot(3,1,3);
plot(out.tout ,out_pid.pid);
title("Controlador PID");

% Configuração do plot

han=axes(fig,'visible','off'); 
han.Title.Visible='on';
han.XLabel.Visible='on';
han.YLabel.Visible='on';
ylabel(han,'Valor de resposta do sistema [ ]');
xlabel(han,'Tempo contínuo [s]');

sgtitle('Controladores P, PI e PID em malha aberta');

% Calculando estabilidade de cada controlador
t = out_pid.tout;

% ========================================
% ================= P ====================
stable = out_pid.p(end);
val = out_pid.p;
ts_P = t(find(val < (0.98*stable) | val > (1.02*stable), 1, 'last'));

% ================= PI ====================
stable = out_pid.pi(end);
val = out_pid.pi;
ts_PI = t(find(val < (0.98*stable) | val > (1.02*stable), 1, 'last'));

% ================= PID ====================
stable = out_pid.pid(end);
val = out_pid.pid;
ts_PID = t(find(val < (0.98*stable) | val > (1.02*stable), 1, 'last'));

f = figure(4);
h = {'P', 'PI', 'PID'};
data = [ts_P ts_PI ts_PID];
tabl = uitable(f, 'data', data, 'columnname', h);