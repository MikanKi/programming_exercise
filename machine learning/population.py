import matplotlib.pyplot as plt
import csv

f = open("population.csv","r")
rd = csv.reader(f)

count = -1

for row in rd:
    count += 1
    if count < 5:
        continue
    elif count == 5:
        x = row[1:]
        print(x)
    else:
        y=[]
        for val in row[1:]:
            percent = float(val)*100
            y.append(percent)
        plt.plot(x,y,label=row[0])
f.close()

plt.title("ratio of population, age 15 to 30")
plt.xlabel("age")
plt.ylabel("ratio (%)")
plt.legend()

plt.show()
