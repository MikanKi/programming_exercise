"""
約数の判定をする（ただし入力は 2 以上に限る）
"""
number = int(input())
count = 0
for i in range(1, number + 1):
    print("check", i, end="") # 改行なし
    if number % i == 0:
        print(" は約数", end="") # 約数のマークを追加（改行なし）
        count += 1
    print() # 改行を追加
print("約数の個数は", count)
