#454403 フェリシア・アイヴィー

class RingBuffer:
    def __init__(self,n=12):    #コンストラクタで n を受け取り、デフォルトで 12 になります。
        self.n = n
        self.result = []        #リストの初期化
        self.count = 1          # count の初期化
    
    def len(self):              #リストの要素数を返す関数
        return len(self.result)
    
    def get(self,i):                #リストの中身をインデックスによって返す関数
        if self.len() > i:          #そのインデックスの要素が存在している場合、
            return self.result[i]   #要素を返す
        else:                       #存在しない場合、
            return None             # None を返す
    
    def add(self,item):                         #リストに要素を追加する関数
        if self.count <= self.n:                # count が n を超えなかったら場合
            self.result.append(item)            #普通にリストに追加します
            self.count += 1
        else:                                   # count が n を超えたら
            index = (self.count % self.n) - 1   #インデックスをまた元に戻し、
            self.result[index] = item           #最初に追加した要素が上書きされる
            self.count += 1

rb1 = RingBuffer(3)
assert rb1.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb1.add(1)
assert rb1.get(0) == 1, "0番目の要素は 1 であるはずです"
rb1.add(2)
rb1.add(3)
rb1.add(4) # 最初の要素である 1 が上書きされる．
assert rb1.get(0) == 4, "0番目の要素は 4 であるはずです"
assert rb1.get(1) == 2, "0番目の要素は 2 であるはずです"
assert rb1.get(2) == 3, "0番目の要素は 3 であるはずです"
assert rb1.len() == 3, "3つの要素が入っているため，長さは3であるはずです"

rb2 = RingBuffer()
assert rb2.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb2.add("item1")
rb2.add("item2")
assert rb2.len() == 2, "2つの要素が入っているため，長さは2であるはずです"
assert rb2.get(5) == None, "5番目の要素は存在しないため，None であるはずです"
