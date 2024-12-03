#454403 フェリシア・アイヴィー

class Point:
    def __init__(self, x, y):   #xx 座標と y 座標を持ち，コンストラクタで初期化します
        self._x = x
        self._y = y
    
    def distance(self, other = None):
        if other == None:                                               #他のPointオブジェクトが渡されなかった場合は，原点 (0, 0) からの距離を計算します
            other = Point(0,0)
        return ((self._x - other._x)**2 + (self._y - other._y)**2)**0.5 #他のPointオブジェクトからの距離を計算する
    
    def __str__(self):                      #文字列表現を返します
        return f"({self._x}, {self._y})"

class Line:
    def __init__(self, p1, p2): #2つの Point オブジェクトを持ち，コンストラクタで初期化します
        self._p1 = p1
        self._p2 = p2
    
    def distance(self):                     #線分の長さを計算する
        return self._p1.distance(self._p2)
    
    def __str__(self):                      #文字列表現を返します
        return f"({self._p1}, {self._p2})"
    
    def is_on(self, other):
        gradient = (self._p1._y - self._p2._y)/(self._p1._x - self._p2._x)  #直線の方程式を求める
        y_intersect = self._p1._y - gradient*self._p1._x
        got_y = gradient*other._x + y_intersect
        if abs(got_y - other._y) < 0.00001:                                 #求めた値got_xと，一致してほしい値want_xの差の絶対値が 0.00001 より小さければ等しいとみなすと良い
            return True
        else:
            return False
