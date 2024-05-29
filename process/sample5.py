i = 1
while i <= 12:
    print(i,"月のデータです。")
    i += 1

total = 0
num = int(input("num を入力 (0を入力で終了)："))
while num > 0:
    total += num
    print(total)
    num = int(input("num を入力 (0を入力で終了)："))
print("total:",total)