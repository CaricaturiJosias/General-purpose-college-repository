import matplotlib.pyplot as plt 
import math
fig = plt.figure(figsize=(4,3))
tempo = []
massa = []

for m in range(5,10):
    m = m/10
    x = m
    y = 2*math.pi*((m/6.506)**0.5)
    massa.append(x)
    tempo.append(y)
plt.plot([0.5102,0.6102,0.7102,0.8102,0.9102],[1.751,1.912,2.060,2.195,2.327],'m1')
plt.plot(massa,tempo,lw = 1)

plt.xlabel('Massa $Kg$',fontsize= 'x-large')
plt.ylabel('Tempo $seg$',fontsize= 'x-large')
plt.title('Massa versus tempo')
fig.savefig('grafico.png')