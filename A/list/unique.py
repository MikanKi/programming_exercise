data = list(map(int, input().split()))
unique = [ ]
print("data =", data)
## ここにコードを追加する
for d in data:
    if d not in unique:
        unique.append(d)
print("unique =", unique)
