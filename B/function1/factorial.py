#454403 フェリシア・アイヴィー  

import sys

def factorial(n):
    fact = n            #結果を初期化
    while n != 1:       #演算を繰り返す
        fact *= (n-1)   #積を求める
        n -= 1          
    return fact         #結果を返す

for arg in sys.argv[1:]:
    n = int(arg)
    print(f"{n}! = {factorial(n)}")
