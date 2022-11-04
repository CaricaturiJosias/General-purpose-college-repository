close all;
clear;
clc;

num = 15;
den = [6000 1100 60 1];

out = sim("Malha_fechada_2016.slx");

% Dados da simulação
t = out.tout;
val = out.ma;

% Reproduzindo o gráfico
figure(1);
plot(t, val);
hold on;

syms s;
transfer = tf(num,den);
transfer = feedback(transfer, 1);
[NUM, DEN] = tfdata(transfer);
func = poly2sym(cell2mat(NUM),s)/poly2sym([cell2mat(DEN) 0],s);
f_t = ilaplace(func);
f_t_h = matlabFunction(f_t);

% Cálculo do valor e tempo de estabilidade
stable = val(end);
% ts = index do tempo (não é o tempo em si)
ts = t(find(val < (0.98*stable) | val > (1.02*stable), 1, 'last'));

% Gerando a reta e a função inteira
x_ft = f_t_h(t);
peaks = findpeaks(x_ft);
peaks_n = findpeaks(-1*x_ft);
if size(peaks, 1) > size(peaks_n, 1)
    peaks = peaks(1:size(peaks)-1);
elseif size(peaks, 1) < size(peaks_n, 1)
    peaks_n = peaks_n(1:size(peaks_n)-1);
end

peaks_total = peaks + peaks_n;
t_peaks = [];
% Obtem o período
for i = 1:size(peaks)
    t_peaks = [t_peaks t(find(x_ft == peaks(i, 1), 1, 'first'))];
end

P = 0;
for i = 1:size(t_peaks,2)
    if i == size(t_peaks,2)
        continue;
    end
    P = (P + (t_peaks(1,i+1)-t_peaks(1,i)))/2;
end

% Calculo do ganho oscilatório
K = 0;
for i = 1:size(peaks_total)
    if i == size(peaks_total,1)
        continue;
    end
    razao = peaks_total(i+1,1)/peaks_total(i,1);
    K = (K + razao)/2;
end

% Visualização
fprintf("\nK: %f", K);
fprintf("\nts: %f\n", ts);

% ==============================================
% ================= P, PI  e PID ===============

P_Kp = 0.5*K;
PI_Kp = 0.45*K;
PI_Ti = P/1.2;
PID_Kp = 0.6*K;
PID_Ti = 0.5*P;
PID_Td = P/8;

f = figure(2);
h = {'Kp', 'Ti', 'Td'};
data = [P_Kp inf 0; PI_Kp PI_Ti 0; PID_Kp PID_Ti PID_Td];
uitable(f, 'data', data, 'columnname', h);

out_pid = sim("Malha_fechada_PID_2016.slx");

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

sgtitle('Controladores P, PI e PID em malha fechada');

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