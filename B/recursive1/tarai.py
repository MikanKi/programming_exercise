#454403 フェリシア・アイヴィー

import sys
import time

count = 0
def tarai(x, y, z):
    global count # 関数の外で定義された変数を関数内で使うために必要
    count = count + 1
    # ここに関数を実装してください
    if x<= y:                                                       # x<=y であれば、
        return y                                                    # y を返す
    else:                                                           # そうでなければ、
        return tarai(tarai(x-1,y,z),tarai(y-1,z,x),tarai(z-1,x,y))  # t(t(x-1,y,z),t(y-1,z,x),t(z-1,x,y)) を返す


def call_tarai(x, y, z):
    global count # 関数の外で定義された変数を関数内で使うために必要
    count = 0
    start = time.time()
    result = tarai(x, y, z)
    end = time.time()
    print(f'tarai({x}, {y}, {z}) = {result} (呼び出し回数: {count}, 経過時間: {(end - start) * 1000}ms)')

if len(sys.argv) == 1:
    call_tarai(10, 5, 0)
    call_tarai(10, 5, 1)
    call_tarai(12, 6, 0)
else:
    x = int(sys.argv[1])
    y = int(sys.argv[2])
    z = int(sys.argv[3])
    call_tarai(x, y, z)
