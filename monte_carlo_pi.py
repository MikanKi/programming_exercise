import random
import math
import matplotlib.pyplot as plt

hit = 0
n = 100000
red_x = []
red_y = []
blue_x = []
blue_y = []

for i in range(n):
    x = random.random()
    y = random.random()
    if math.sqrt(x*x + y*y) <= 1:
        hit += 1
        red_x.append(x)
        red_y.append(y)
    else:
        blue_x.append(x)
        blue_y.append(y)
pi = 4*hit/n
print(pi)

plt.figure(figsize=(6,6))
plt.title("Monte Carlo Simulation (pi={},n={})".format(pi,n))
plt.scatter(red_x,red_y,color="red",s=1)
plt.scatter(blue_x,blue_y,color="blue",s=1)
plt.show()
