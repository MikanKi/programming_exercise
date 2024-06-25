data1 = [1,2,3,4,5]
data2 = [6,7,8,9,10]

print("data1:",data1)
print("data2:",data2)

data1 += data2
data3 = data1.copy()

print("data3:",data3)

for r in reversed(data3):
    print(r,end=" ")
print()