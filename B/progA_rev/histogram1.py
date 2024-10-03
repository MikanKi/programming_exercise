import matplotlib.pyplot as plt
import sys

data = []
f = open(sys.argv[1],"r")
for line in f.readlines():
    data.append(int(line))
f.close()

plt.hist(data,bins=20)
plt.title("bins=20")
plt.show()
