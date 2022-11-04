from scipy.stats import poisson
import matplotlib.pyplot as plt 

print(1-poisson.cdf(10,10))

k = [i for i in range(0,11)]
print(1-sum(poisson.pmf(k, 10)))

hora = 60
resp = list()

for i in range(1,hora+1):
    resp.append(poisson.rvs(10))

fila = list()
current = 0

for i in range(1,hora):
    if i == 1:
        if resp[i] >= 10:
            fila.append(resp[i]-10)
        else:
            fila.append(0)
    else:
        if resp[i] >= 10: # More than 10 incoming
            fila.append(resp[i]+fila[i-2]-10)
        else: # Less than 10 incoming
            if (resp[i]+fila[i-2] >= 10):
                fila.append(resp[i]+fila[i-2]-10)
            else:
                fila.append(0)
plt.figure()
plt.plot(resp)
plt.title("Trafego simulado")
plt.xlabel("Trafego")
plt.ylabel("Tempo [min]")
plt.show(block=False)

fig, ax = plt.subplots()
ax.plot(resp, '-b', label='Trafego simulado')
ax.plot(fila, '--r', label='Fila de espera')
plt.xlabel("Trafego")
plt.ylabel("Tempo [min]")
ax.legend()
plt.show()
