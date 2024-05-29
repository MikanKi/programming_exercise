"""
入力した値の合計を得る
"""
total = 0
num = int(input("num = "))  # 一つ目の数の入力
while num > 0:
    total = total + num
    print(total)
    num = int(input("num = "))  # 二つ目以降の数の入力
print("total = ", total)
