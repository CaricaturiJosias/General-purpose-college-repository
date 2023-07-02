%% Estudantes
% Gabriel Vitor Cezário
% Mateus Ferro Antunes de Oliveira
% Tasi Guilhen Pasin

close all;
clear;
clc;
syms s;

%% Inicialização de variáveis

% Tempo de simulação e Step
Time_sim = 1550;
Ts = 0.01;

Time_sim_PID = 175;
Ts_PID = 0.001;

satur = 10000;

% Valores colocados na entrada com seu respectivo tempo no eixo
input_val =  [20, 30, 40, 50, 70, 70];
Times = [10, 175, 450, 850, 1250, Time_sim];

% Montando a lista - relacionando tempo com seu valor
V_Profile = [
    0 0;
    Times(1) 0;
    Times(1) input_val(1);
    Times(2) input_val(1);
    Times(2) input_val(2);
    Times(3) input_val(2);
    Times(3) input_val(3);
    Times(4) input_val(3);
    Times(4) input_val(4);
    Times(5) input_val(4);
    Times(5) input_val(5);
    Time_sim input_val(5);
    ];

% Puxando a malha do simulink
sim('SphericalTank_2016b');


%% Plotagem dos gráficos de entrada e saída
figure();
subplot(211);
plot(V(:,1),V(:,2),'color',[0, 0.5, 0],'linewidth',4);
xlabel('Time [s]');
ylabel('Valve Position [-]');
ylim([-0.1 100.1]);
grid on;

subplot(212);
plot(H_Read(:,1),H_Read(:,2),'b','linewidth',4);
ylabel('Fluid Level [m]');
ylim([-0.1 4.1]);
grid on;


%% Calculo de valores para cada modelo dentro do sistema

% A partir da leitura, guarda tempo e saída
tempo = H_Read(:,1);
saida = H_Read(:,2);
 
% Pre inicializando as variáveis - Array/Listas
[tal, Ks, T, estado_estacio, ...
 PID_Kps, PID_Tis, PID_Tds, P_Kps, ...
 PI_Kps, PI_Tis, kA] = deal(zeros(1, size(input_val, 2)));

for i = 2:size(input_val, 2)
    % Traduz tempo para um índice
    index_time = Times(i)/Ts;
    index_time_prev = Times(i-1)/Ts;
    
    % Valor de estabilidade para o degrau i
    estado_estacio(i) = saida(index_time) * 0.98;
    % Constante de tempo
    tal(i) = (Ts * find(saida < estado_estacio(i), 1, 'last') - Times(i-1))/4;
    % Proporção degrau/saída
    Ks(i) = estado_estacio(i)/input_val(i);
    
    % Valor de saída correspondendo a 2% do sinal de saída do degrau i
    delta = (saida(index_time) - saida(index_time_prev)) * 0.02;
    estado_atraso = saida(index_time_prev) + delta;
    % Período de tempo até chegar a 2% do valor do degrau
    T(i) = (Ts * find(saida > estado_atraso, 1, 'first') - Times(i-1));


    % Função de Transferência genérica de 1° grau
    M = (Ks(i) / (tal(i) * s + 1)) * exp(-T(i) * s);
    M_tf = pade(tf(Ks(i), [tal(i) 1], 'InputDelay', T(i)), 1);

    figure(2)
    [r, k] = rlocus(M_tf);
    rlocus(M_tf);
    sgrid;
    xlim([-6 13]);
    hold on;

    limit_index = find(real(r(1,:))<=0, 1, 'last');
    polos = r(:,limit_index);
    kA(i) = k(limit_index);

    % z = zero(M_tf);
    % Kabs = @(x) (abs(x+polos(1))*abs(x+polos(2)))/abs(x+z);
    % kT(i) = Kabs(max(polos(1),polos(2)));

    % [PI, PID] = Control(Ks(i), tal(i), T(i));

    % figure(3)
    % M_PID = feedback(PID * M_tf, 1);
    % % [y,t] = step(M_PID);
    % step(M_PID);
    % legend("M\_PID 1", "M\_PID 2", "M\_PID 3", "M\_PID 4", "M_PID 5");
    % hold on;
    % 
    % figure(4)
    % M_PI = feedback(PI * M_tf, 1);
    % % [y,t] = step(M_PI);
    % step(M_PI);
    % legend("M\_PI 1", "M\_PI 2", "M\_PI 3", "M\_PI 4", "M_PI 5");
    % hold on;
    
    [PID_Kp, PID_Ti, PID_Td, PI_Kp, PI_Ti, P_Kp] = ControlParam(Ks(i), tal(i), T(i));
    
    % Salva num Array os valores de cada modelo
    P_Kps(i) = P_Kp;

    PI_Kps(i) = PI_Kp;
    PI_Tis(i) = PI_Ti;

    PID_Kps(i) = PID_Kp;
    PID_Tis(i) = PID_Ti;
    PID_Tds(i) = PID_Td;   

    sim('PIDTank_2016b.slx');
    
    tempo = H_Read(:,1);

    % Resultado da 3.3...
    figure(3);
    plot(tempo, saidaPID); hold on;
    legend("M\_PID 1", "M\_PID 2", "M\_PID 3", "M\_PID 4", "M\_PID 5");
    
    figure(4);
    plot(tempo, saidaPI); hold on;
    legend("M\_PI 1", "M\_PI 2", "M\_PI 3", "M\_PI 4", "M\_PI 5");
    
    figure(5);
    plot(tempo, saidaP); hold on;
    legend("M\_P 1", "M\_P 2", "M\_P 3", "M\_P 4", "M\_P 5");
    % ---------
end

% Menor kA é o ganho mais perigoso, usamos ele
kA = kA(2:end);

% Tirando os zeros que ficaram na posição 1
P_Kps = P_Kps(2:end);
PI_Kps = PI_Kps(2:end);
PI_Tis = PI_Tis(2:end);
PID_Kps = PID_Kps(2:end);
PID_Tis = PID_Tis(2:end);
PID_Tds = PID_Tds(2:end);

% Coletando o index dos ganhos críticos mínimos e máximos
[~, index_min] = min(kA);
% [~, index_max] = max(kA);

% Utilizando o index do mínimo pra usar o PID mais seguro em teoria
P_Kp = P_Kps(index_min);

PI_Kp = PI_Kps(index_min);
PI_Ti = PI_Tis(index_min);

PID_Kp = PID_Kps(index_min); 
PID_Ti = PID_Tis(index_min); 
PID_Td = PID_Tds(index_min); 

% Mesmo tempo da primeira simulação 
% Times = [10, 175, 450, 850, 1250, Time_sim];

% Ajustando o profile para os sinais de saída da
% primeira simulação para comparação

% por estar com controlador tem que ser o sinal
% que queremos não os proporcionais de antes

% no caso de duvida estado_estacio(1) = 0
V_Profile = [
    0 estado_estacio(1);
    Times(1) estado_estacio(1);
    Times(1) estado_estacio(2);
    Times(2) estado_estacio(2);
    Times(2) estado_estacio(3);
    Times(3) estado_estacio(3);
    Times(3) estado_estacio(4);
    Times(4) estado_estacio(4);
    Times(4) estado_estacio(5);
    Times(5) estado_estacio(5);
    Times(5) estado_estacio(6);
    Time_sim estado_estacio(6);
    ];

% Fizemos um V_Profile modificado para avaliar o comportamento...
% V_Profile = [
%     0 estado_estacio(1);
%     Times(1) estado_estacio(1);
%     Times(1) estado_estacio(3);
%     Times(2) estado_estacio(3);
%     Times(2) estado_estacio(4);
%     Times(3) estado_estacio(4);
%     Times(3) estado_estacio(5);
%     Times(4) estado_estacio(5);
%     Times(4) estado_estacio(4);
%     Times(5) estado_estacio(4);
%     Times(5) estado_estacio(6);
%     Time_sim estado_estacio(6);
%     ];

sim('PI_SphericalTank_2016b.slx');


% Resultado da 3.3...
figure(6);

subplot(311)
plot(H_Read(:,1), saidaP2,  'k','linewidth', 3); hold on;
plot(V(:,1), V(:,2), 'color', [0.8500 0.3250 0.0980],'linewidth',2);
ylim([0 4.5]); grid on;
legend("Controlador P", "Sinal de referência", Location="northwest");
ylabel("Fluid Level [m]"); xlabel("Time [s]");
title("Controlador P comparado com o Sinal de Referência");

subplot(312)
plot(H_Read(:,1), saidaPI2, 'color', [0.4660 0.6740 0.1880],'linewidth', 3);  hold on;
plot(V(:,1), V(:,2), 'color', [0.8500 0.3250 0.0980],'linewidth',2);
ylim([0 4.5]); grid on;
legend("Controlador PI", "Sinal de referência", Location="northwest");
ylabel("Fluid Level [m]"); xlabel("Time [s]");
title("Controlador PI comparado com o Sinal de Referência");

subplot(313)
plot(H_Read(:,1), saidaPID2,'.-', 'color', [0 0.4470 0.7410],'linewidth', 3);  hold on;
plot(V(:,1), V(:,2), 'color', [0.8500 0.3250 0.0980],'linewidth',2);
ylim([0 4.5]); grid on;
legend("Controlador PID", "Sinal de referência", Location="northwest");
ylabel("Fluid Level [m]"); xlabel("Time [s]");
title("Controlador PID comparado com o Sinal de Referência");
% ------

%% Utilidades

time = H_Read(:,1);

sim_acaoControleP = acaoControleP;
sim_acaoControlePI = acaoControlePI;
sim_acaoControlePID = acaoControlePID;

% [ISE, IAE, MSE, RMSE, IADU, ST, RT, MD, OS] = Performance(sim_acaoControleP, saidaP2, time);
% [ISE, IAE, MSE, RMSE, IADU, ST, RT, MD, OS] = Performance(sim_acaoControlePI, saidaPI2, time);
% [ISE, IAE, MSE, RMSE, IADU, ST, RT, MD, OS] = Performance(sim_acaoControlePID, saidaPID2, time);

% Não gostamos dos resultados, e você?






















