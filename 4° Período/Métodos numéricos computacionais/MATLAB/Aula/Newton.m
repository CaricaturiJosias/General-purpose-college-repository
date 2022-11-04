function Newton()

x = sym('x'); 
f = input("Insira f(x) = ");
x0 = input("Insira x0 = ");
e = input("Insira a precisão e = ");
m = input("Insira o numero máx de interações m = ");
 
fd = diff(f); %calculo de diferencial (derivada de f em relação a x (df/dx))
 
k = 0;
fprintf('\nx(%d) = %.10f ',k,x0)

while k <= m
    k = k+1;
    if subs(fd,x0) == 0 
        disp('Derivada igual a zero, escolha outro ponto inicial');
        return
    end
    xk = (x0 - subs(f,x0)/subs(fd,x0));
    erro = abs(xk-x0)/max([1,abs(xk)]);
    fprintf('x(%d) = %.5f ; erro = %.5f \n',k, xk,erro);
    if erro < e
        fprintf("\n A raiz é x(%d) = %.20f; erro = %.20f",k, xk, erro);
        return
    end
    x0 = xk;
end