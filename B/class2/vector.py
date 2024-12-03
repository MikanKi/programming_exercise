#454404 フェリシア・アイヴィー

class Vector:
    def __init__(self,*arg):    #コンストラクタ．n個の引数（可変長）を受け取り，ベクトルを表す
        self.vector = list(arg)

    def __add__(self,other):                                    #ベクトル同士の足し算を計算し，新しいベクトルを返す
        result = []
        if len(self) != len(other):                             #要素数の異なるベクトル同士の足し算は計算できないので，None が返る
            return None
        else:
            for i in range(len(self)):
                result.append(self.vector[i]+other.vector[i])
            return result

    def __mul__(self,other):                            #ベクトル同士の内積を計算し，スカラー値を返す
        sum = 0
        if len(self) != len(other):                     #要素数の異なるベクトル同士の内積は計算できないので，None が返る
            return None
        else:
            for i in range(len(self.vector)):
                sum += (self.vector[i]*other.vector[i])
            return sum

    def __getitem__(self,key):  #ベクトルの要素を取得する
        return self.vector[key]

    def __len__(self):          #ベクトルの長さを返す
        return len(self.vector)

    def __str__(self):                  #ベクトルの文字列表現を返す
        return f"{tuple(self.vector)}"

    def norm(self):                         #ベクトルのノルム（大きさ）を計算し，返す
        sum = 0
        for i in range(len(self.vector)):
            sum += (self.vector[i]**2)
        return sum ** 0.5