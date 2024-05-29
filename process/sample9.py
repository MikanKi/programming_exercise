num = int(input("何月の処理を飛ばしますか？(1~12)"))
for i in range(12):
    if (i+1) == num:
        continue
    print(i+1,"月のデータです。")

number = int(input("num input:"))
count = 0
for i in range(1, number+1):
    if number % i != 0:
        continue
    print(i,"は約数",end="")
    count += 1
    print()
print("約数の個数は",count)
