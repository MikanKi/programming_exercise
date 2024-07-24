import random
count = [0] *10

for i in range(10000):
    n = random.randint(0,999)
    count[n//100] += 1

for j in range(10):
    print("{0:>3} ~ {1:<3} : {2}".format(j*100,j*100+99,count[j]))

