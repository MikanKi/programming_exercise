#454403 フェリシア・アイヴィー
import math
import matplotlib.pyplot as plt

class Lissajous:
    def __init__(self,a,b,delta,A=1,B=1):
        self.A = A
        self.B = B
        self.a = a
        self.b = b
        self.delta = delta
    
    def calc(self):
        self.x = []
        self.y = []
        for i in range(0, 361): # 0〜360度まで．
            t = i * (math.pi / 180)       # ラジアンに変換する．
            self.x.append(self.A*math.cos(self.a*t))           # x に値を追加する（x.append(...)）．
            self.y.append(self.B*math.sin(self.b*t + self.delta))   # y に値を追加する（y.append(...)）．
    
    def draw(self):
        plt.plot(self.x, self.y)
        plt.text(0, 1.15, f"A={self.A}, B={self.B}, a={self.a}, b={self.b}, δ={self.delta}", fontsize=12, ha="center")
        plt.axis("equal") # グラフの縦横比を 1:1 にする．
        plt.show()

A = 1
B = 1

a = 3
b = 4
delta = math.pi / 4

x = []
y = []


