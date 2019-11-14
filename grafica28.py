import os
import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(1,10,2001)

plt.figure()
data = np.loadtxt("ecuaciones.dat")
n = len(data)
plt.plot(x,data[:,0])
plt.title('Integral')
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig("resultados.png")