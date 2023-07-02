function [Kp, Ti] = SinteseParam(tal, K, atraso)
% function [PI_Kp, PI_Ti] = SinteseParam(tal, K, atraso)
    format long;
    gama = atraso;
    
    % PI_Kp = tal/(K*(gama + atraso));
    % PI_Ti = min(tal, 4*(atraso+gama));
    
    Kp = tal/(K*(gama + atraso));
    Ti = min(tal, 4*(atraso+gama));
end


% function [PI, PID] = Control(K, tal, T)
%     format long;
% 
%     % Controlador PI
%     KPI = 0.9 * ((tal) / (K * T));
%     TiPI = T / 0.3;
% 
%     PI = KPI * tf([TiPI 1], [TiPI 0]);
% 
%     % Controlador PID
%     KPID = 1.2 * ((tal) / (K * T));
%     TiPID = 2 * T;
%     TdPID = 0.5 * T;
% 
%     PID = KPID * tf([TiPID*TdPID TiPID 1], [TiPID 0]);
% end