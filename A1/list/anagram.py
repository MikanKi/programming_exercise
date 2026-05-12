data = list(map(int, input().split()))
## ここにコードを追加する
length = len(data)
half = length//2
remain = length%2

head = data[:half]
tail = data[half+remain:]
tail.reverse()

if head == tail:
    print("Anagram")
else:
    print("Not Anagram")
