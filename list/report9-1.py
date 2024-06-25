points = [20, 0, 35, 14, 40, 8]
sum = 0
count = 0
max = 0
min = 100
avg = 0
for p in points:
    if p == 0:
        continue
    if p > max:
        max = p
    elif p < min:
        min = p
    sum += p
    count += 1
if count == 0:
    max = 0
    min = 0
else:
    avg = sum/count
print("最高点：", max)
print("最低点：", min)
print("平均点：", avg)

