string = list(map(str, input().split()))
string_list = list(string[0])
## ここにコードを追加する
length = len(string_list)
half = length//2
remain = length%2

head = string_list[:half+remain]
tail = string_list[half:]
tail.reverse()

if head == tail:
    print("Anagram")
else:
    print("Not Anagram")
