#454403 フェリシア・アイヴィー

class Stack:
    def __init__(self,result = None):   #リストを初期化する
        if result == None:              #受け取るリストがなかったら、新しいリストを作る
            self.result = []
        else:
            self.result = result
    
    def push(self,item):                #リストの一番最後に item を追加します
        self.result.append(item)
    
    def pop(self):                          #リストの一番最後の要素を取り出して返します
        if self.len() != 0:
            last_elem = self.peek()
            del self.result[self.len()-1]   #リストからは最後の要素を削除します
            return last_elem
        else:                               #要素が存在しない場合は None を返します
            return None

    def peek(self):                         #リストの一番最後の要素を返します
        return self.result[self.len()-1]

    def len(self):                          #スタックにある要素数を返します
        return len(self.result)



s1 = Stack()
s1.push("This")
s1.push("is")
s1.push("stack")
s1.push("test")

assert s1.len() == 4, "スタックの長さは4になっているはずです"
assert s1.peek() == "test", "peek() は最後の要素である test を返すべきです"
assert s1.len() == 4, "peek() は要素の長さを変更しません"

assert s1.pop() == "test",  "pop() は最後の要素である test を返すべきです"
assert s1.pop() == "stack", "pop() は最後の要素である stack を返すべきです"
assert s1.pop() == "is",    "pop() は最後の要素である is を返すべきです"
assert s1.pop() == "This",  "pop() は最後の要素である This を返すべきです"
assert s1.len() == 0, "スタックの長さは0になっているはずです"

s2 = Stack([1, 2, 3, 4, 5]) # コンストラクタで要素を指定できる．
assert s2.len() == 5, "スタックの長さは5になっているはずです"
s2.pop()
s2.pop()
s2.pop()
s2.pop()
s2.pop()
assert s2.len() == 0, "スタックの長さは0になっているはずです"

s3 = Stack()
assert s3.pop() == None, "空のスタックから pop() すると None が返るべきです"
