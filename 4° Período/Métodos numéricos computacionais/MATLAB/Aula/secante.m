function [x2] = secante(f,x0,x1,e,m)

x = sym('x');
k = 1;

fprintf('x(0) = %f \n',x0) 
fprintf('x(1) = %f \n',x1)

while k <= m
    k = k+1;
    
    x2 = eval((x0*subs(f,x1)-x1*subs(f,x0))/(subs(f,x1)-subs(f,x0)) );
    erro = abs(x2-x0)/max([1,abs(x2)]);
    fprintf('x(%d) = %.20f ; erro = %.10f \n',k, x2,erro);
    if erro < e
        fprintf("\n A raiz é x(%d) = %.20f; erro = %.10f\n",k, x2, erro);
        return
    end
    x0 = x1;
    x1 = x2;
end