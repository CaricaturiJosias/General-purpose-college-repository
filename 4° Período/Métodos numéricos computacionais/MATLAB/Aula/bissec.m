%comentario
function bissec()

x = sym('x');                       %declarando que x é variavel
f = input('Insira o f(x) = ');      %f(x)
a = input('Insira o valor de a = ');%começo do invervalo
b = input('Insira o valor de b = ');%fim do intervalo
e = input('Insira a precisão = ');
m = input('Insira o numero máximo de interações = ');
if subs(f,a)*subs(f,b)>0
    disp('Valores de a e b não convergentes!')
    fprintf('f(a) = %f \n', subs(f,a))
    fprintf('f(b) = %f \n', subs(f,b))
    return
end

k = 1;
while k<m
   xk = (a+b)/2;
   fprintf('x(%d)=%f\n',k,xk)
   if subs(f,a)*subs(f,xk) < 0
       b = xk;
   else
       a = xk;
   end
   k=k+1;
   xk1 = (a+b)/2;
   if abs(xk1-xk)<e*([1,abs(xk1)])
       fprintf('\nA raiz é x(%d) = %f',k,xk)
       return
   end
end










