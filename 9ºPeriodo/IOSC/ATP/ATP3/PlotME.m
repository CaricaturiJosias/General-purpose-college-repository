%% Estudantes
% Gabriel Vitor Cezário
% Mateus Ferro Antunes de Oliveira
% Tasi Guilhen Pasin

close all; clear; clc;
syms s;

%% Plot features
load Patient;
figure();

%% Simulando uma, pegando parametros e criando um controlador
patient = 1;
delay = Patient(patient, 1);      % td é delay
k = Patient(patient, 2);
E50 = Patient(patient, 3);
gamma = Patient(patient, 4);
E0 = Patient(patient, 5);

out = sim('Propofol_OL_2016');
Yt = out.Yt;

saida = Yt(:,1);
t = Yt(:,2);

figure(2);
subplot(211);
plot(Yt(:,1),Yt(:,2),'b','linewidth',4); hold on;
ylabel('DOH WAV.CNS [%]');
ylim([-1 101])
yline(40,'--r','LineWidth',2);
yline(60,'--r','LineWidth',2);
grid on;

subplot(212);
plot(Ut(:,1),Ut(:,2),'color',[0, 0.5, 0],'linewidth',4);
xlabel('Time [min]');
ylabel('Infusion rate [mcg/kg/min]');
ylim([-1 500])
grid on;

% Traduz tempo para um índice
index_time = t(end);
Ts = t(2)-t(1); % Time step

% Valor de estabilidade para o degrau i
estado_estacio = saida(index_time) * 0.98;

% Constante de tempo
tal = (Ts * find(saida <= estado_estacio, 1, 'last'))/4;
% Proporção degrau/saída
Ks = estado_estacio/input_val;

% Valor de saída correspondendo a 2% do sinal de saída do degrau i
delta = (saida(index_time) - saida(index_time_prev)) * 0.02;
estado_atraso = saida(index_time_prev) + delta;
% Período de tempo até chegar a 2% do valor do degrau
T = (Ts * find(saida > estado_atraso, 1, 'first'))/4;

% Calculo de erro tem o base no 100 ao invés do 0
for i = 25
    patient = i;

    delay = Patient(patient, 1);      % td é delay
    k = Patient(patient, 2);
    E50 = Patient(patient, 3);
    gamma = Patient(patient, 4);
    E0 = Patient(patient, 5);
    
    Param = [k, k, delay];
    [AKp, ATi, ATd, AMetodo] = PID_Tuning(Param, "MF");
    AKp = -AKp;

    for j = 1:length(AKp)
        [Kp, Ti, Td] = deal(AKp(j), ATi(j), ATd(j));
        out = sim('Propofol_Children_2016');
        figure(1);
        plot(Y(:,2), Y(:,1));
    end
end