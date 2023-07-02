function [Kp, Td, Ti, Metodos] = PID_Tuning(Tuning_Param,Type)
%PID_Tuning Gets the PID control parameters for each of the methods
% Details ------------------------------------------------------------------
% Gets the PID parameters for each method described ahead based on direct
% control analysis of the step response of the system

% Open Loop (MA)
    % Se for malha aberta (Type == 'MA')
    if strcmp('MA', Type)
        % ==============================================
        % ================= P, PI and PID ==============
        % Variáveis para essa simulação
        K   = Tuning_Param(1);
        tal = Tuning_Param(2);
        T   = Tuning_Param(3);
        % "ZNMA"      "ParrMA"        "ChiMA"  ...
        % "Bor&GriMA" "MurMA"         "LipMA"  ...
        % "AlfMA1"    "AlfMA2"        "PmaMA1" ...
        % "PmaMA2"    "CHMA1"         "CHMA2"  ...
        % "CCMA"
        Metodos = ["ZNMA"      "ParrMA" "ChiMA"  ...
                   "Bor&GriMA" "MurMA"  "LipMA"  ...
                   "AlfMA1"    "AlfMA2" "PmaMA1" ...
                   "PmaMA2"    "CHMA1"  "CHMA2"  ...
                   "CCMA"];
        % Inicialização de listas para acomodar todos os valores de cada
        % componente dos controladores
        Kp = zeros(1,size(Metodos,2));
        Td = zeros(1,size(Metodos,2));
        Ti = zeros(1,size(Metodos,2));
        
        %% ============ PI - Wolfe
        Kp(1) = (0.2)/(K*T);
        Ti(1) = 0.3*T;
        
        %% ============ PI - Callender 1
        Kp(2) = (0.568)/(K*T);
        Ti(2) = 3.64*T;
        
        %% ============ PI - Callender 2
        Kp(3) = (0.65)/(K*T);
        Ti(3) = 2.6*T;
        
        %% ============ PI - Callender 3
        Kp(4) = (0.79)/(K*T);
        Ti(4) = 3.95*T;
        
        %% ============ PI - Callender 4
        Kp(5) = (0.95)/(K*T);
        Ti(5) = 3.3*T;
        return
    end
    
    %% Closed Loop (MF)
    if strcmp('MF', Type)
        K = Tuning_Param(1);
        T = Tuning_Param(2);
%         Metodos = ["ZNMF"      "FarrMF"      "Mc&JoMF"    ...
%                    "Atk&DavMF" "Car&PetMF1"  "Car&PetMF2" ...
%                    "ParrMF1"   "ParrMF2"     "ParrMF3"    ...
%                    "TinMF"     "BliMF"       "CorrMF"     ...
%                    "Ch&YaMF"   "DPaMF1"      "DPaMF2"     ...
%                    "McMiMF1"   "McMiMF2"     "Ca&GoMF"    ...
%                    "LuoMF"     "Kar&KalMF"   "Bel&LuyMF " ...
%                    "WojMF"     "YuMF"        "RobMF"      ...
%                    "SmiMF"];
        Metodos = ["ZNMF"      "FarrMF"     "Mc&JoMF"    ...
                   "Atk&DavMF" "Car&PetMF1" "Car&PetMF2" ...
                   "ParrMF1"   "ParrMF2"    "ParrMF3"    ...
                   "TinMF"     "BliMF"      "CorrMF"     ...
                   "Ch&YaMF"   "DPaMF1"     "DPaMF2"     ...
                   "McMiMF1"   "McMiMF2"    "Ca&GoMF"    ...
                   "LuoMF"     "Kar&KalMF"  "Bel&LuyMF"  ...
                   "WojMF"     "YuMF"       "RobMF"      ...
                   "SmiMF"];

        Kp = zeros(1,size(Metodos,2));
        Td = zeros(1,size(Metodos,2));
        Ti = zeros(1,size(Metodos,2));

        %% ============ PID - ZN
        Kp(1) = 0.6*K;
        Ti(1) = 0.5*T;
        Td(1) = 0.125*T;

        %% ============ PID - Farrington
        Kp(2) = 0.33*K;
        Ti(2) = T;
        Td(2) = 0.1*T;

        %% ============ PID - McAvoy and Johnson
        Kp(3) = 0.54*K;
        Ti(3) = T;
        Td(3) = 0.2*T;

        %% ============ PID - Atkinson and Davey
        Kp(4) = 0.25*K;
        Ti(4) = 0.75*T;
        Td(4) = 0.25*T;

        %% ============ PID - Carr and Pettit
        Kp(5) = 0.667*K;
        Ti(5) = T;
        Td(5) = 0.167*T;

        %% ============ PID - Carr and Pettit 2
        Kp(6) = 0.5*K;
        Ti(6) = 1.5*T;
        Td(6) = 0.167*T;

        %% ============ PID - Parr
        Kp(7) = 0.5*K;
        Ti(7) = T;
        Td(7) = 0.2*T;

        %% ============ PID - Parr 2
        Kp(8) = 0.5*K;
        Ti(8) = T;
        Td(8) = 0.25*T;

        %% ============ PID - Parr 3
        Kp(9) = 0.5*K;
        Ti(9) = 0.34*T;
        Td(9) = 0.08*T;
        
        %% ============ PID - Tinham
        Kp(10) = 0.4444*K;
        Ti(10) = 0.6*T;
        Td(10) = 0.19*T;
  
        %% ============ PID - Blickley
        Kp(11) = 0.5*K;
        Ti(11) = T;
        Td(11) = 0.125*T;

        %% ============ PID - Corripio
        Kp(12) = 0.75*K;
        Ti(12) = 0.63*T;
        Td(12) = 0.1*T;

        %% ============ PID - Chen and Yang
        Kp(13) = 0.27*K;
        Ti(13) = 2.4*T;
        Td(13) = 1.32*T;

        %% ============ PID - De Paor
        Kp(14) = 0.906*K;
        Ti(14) = 0.5*T;
        Td(14) = 0.125*T;

        %% ============ PID - De Paor 2
        Kp(15) = 0.866*K;
        Ti(15) = 0.5*T;
        Td(15) = 0.125*T;

        %% ============ PID - McMillan
        Kp(16) = 0.5*K;
        Ti(16) = 0.5*T;
        Td(16) = 0.125*T;

        %% ============ PID - McMillan 2
        Kp(17) = 0.3*K;
        Ti(17) = 0.5*T;
        Td(17) = 0.125*T;

        %% ============ PID - Calcev and Gorez
        Kp(18) = 0.3536*K;
        Ti(18) = 0.1592*T;
        Td(18) = 0.0398*T;

        %% ============ PID - Luo et al
        Kp(19) = 0.48*K;
        Ti(19) = 0.5*T;
        Td(19) = 0.125*T;

        %% ============ PID - Karaboga and Kalinli
        Kp(20) = 0.32*K;
        Ti(20) = 0.213*T;
        Td(20) = 0.133*T;

        %% ============ PID - Luyben and Luyben
        Kp(21) = 0.46*K;
        Ti(21) = 2.2*T;
        Td(21) = 0.16*T;

        %% ============ PID - Wojsznis
        Kp(22) = 0.4*K;
        Ti(22) = 0.333*T;
        Td(22) = 0.083*T;

        %% ============ PID - Yu
        Kp(23) = 0.33*K;
        Ti(23) = 0.5*T;
        Td(23) = 0.125*T;

        %% ============ PID - Robbins
        Kp(24) = 0.45*K;
        Ti(24) = 0.5*T;
        Td(24) = 0.25*T;

        %% ============ PID - Smith
        Kp(25) = 0.75*K;
        Ti(25) = 0.625*T;
        Td(25) = 0.1*T;
        return
    end
end