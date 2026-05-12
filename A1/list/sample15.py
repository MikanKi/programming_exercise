data = list(map(int, input().split()))
## ここにコードを追加する
length = len(data)
half = length//2

head = data[:half]
print(head)
if length % 2 == 0:
    tail = data[half:]
else:
    tail = data[half+1:]
print(tail)
tail.reverse()

if head == tail:
    print("Anagram")
else:
    print("Not Anagram")

