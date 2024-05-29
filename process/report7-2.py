total = 0
count = 0
avg = 0
num = int(input("num を入力 (0を入力で終了)："))
while num > 0:
    total += num
    count += 1
    avg = total/count
    print(avg)
    num = int(input("num を入力 (0を入力で終了)："))

print("average:",avg)