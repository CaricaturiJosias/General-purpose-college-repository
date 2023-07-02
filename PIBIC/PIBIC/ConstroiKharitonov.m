%Polinômios de Kharitonov

% fsw=10020;
% fs=20040;
% vdc=400;
% vg=220;
% lc=1e-3;
% lg1=0.3e-3;
% cf=62e-6;
% lg2min=0.1;
% lg2max=1.5;
% rg=0.1;
% rf=1;
% 
% %rc e rg1 são correntes parasitas (valor rc?)
% %rg=rg1+rg2
% %lg=lg1+lg2
% 
% f1=cf*rf;
% g3=cf*lc*lg;
% g2=cf*rf*(lc+lg)+cf*lc*rg+cf*lg*rc;
% g1=lc+lg+rf*rg*cf+cf*rc*(rf+rg);
% g0=rg+rc;

Num_min=flip([1.8 0.8 1.4]);
Num_max=flip([4.2 1.2 2.6]);

%Num_min=flip([800 30]);
%Num_max=flip([1200 70]);

%Num_min=flip([8.011e-2 7.410e-1 2.704e-1 5.674e-3]);
%Num_max=flip([4.888e-2 4.944e-1 1.395e-1 2.658e-3]);

Den_min=flip([]);
Den_max=flip([]);
CNum=[];
CDen=[];

K_even_max=[];
K_even_min=[];
K_odd_max=[];
K_odd_min=[];

size_num=size(Num_min,2);
j=1;k=1;
for i=1:size_num
    if mod(i,2)~=0 %pares
        if mod(j,2)~=0
            K_even_max=cat(2,K_even_max,Num_max(i));
            K_even_min=cat(2,K_even_min,Num_min(i));
            K_odd_max=cat(2,K_odd_max,1);
            K_odd_min=cat(2,K_odd_min,1);
            j=j+1;
        else
            K_even_max=cat(2,K_even_max,Num_min(i));
            K_even_min=cat(2,K_even_min,Num_max(i));
            K_odd_max=cat(2,K_odd_max,1);
            K_odd_min=cat(2,K_odd_min,1);
            j=j+1
        end
    else
        if mod(k,2)~=0
            K_even_max=cat(2,K_even_max,1);
            K_even_min=cat(2,K_even_min,1);
            K_odd_max=cat(2,K_odd_max,Num_max(i));
            K_odd_min=cat(2,K_odd_min,Num_min(i));
            k=k+1;
        else
            K_even_max=cat(2,K_even_max,1);
            K_even_min=cat(2,K_even_min,1);
            K_odd_max=cat(2,K_odd_max,Num_min(i));
            K_odd_min=cat(2,K_odd_min,Num_max(i));
            k=k+1;     
        end
    end
end

K1=flip(K_even_min.*K_odd_min);
K2=flip(K_even_min.*K_odd_max);
K3=flip(K_even_max.*K_odd_min);
K4=flip(K_even_max.*K_odd_max);