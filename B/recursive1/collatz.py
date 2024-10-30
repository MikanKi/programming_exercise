#454403 フェリシア・アイヴィー

import sys

def collatz(x, list):
    list.append(x)
    if x != 1:
        # 以下の pass の代わりに x が奇数のとき，偶数のときそれぞれの
        # 処理（x / 2, 3 * x + 1）を実装して，x + 1 を求めてください
        if x % 2 == 0:
            return collatz(x // 2,list)
        else:
            return collatz(3*x + 1,list)
        

for value in sys.argv[1:]:
    n = int(value)
    list = []
    collatz(n, list)
    print(f'collatz({n}) = {list} ({len(list)} steps)')
