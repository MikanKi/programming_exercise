#454403 フェリシア・アイヴィー

import random # 乱数を生成するためのライブラリ

randoms = []

max = 0     # 最大値，
min = 1000  # 最小値，
sum = 0     # 合計値の初期値を適切に設定しましょう．

for i in range(100):                # 100 回繰り返す．
    num = random.randint(1, 1000)   # 1 以上 10 以下の乱数を生成する．
    randoms.append(num)             # randoms に num を追加する．
    if num > max:                   # 最大値を更新する
        max = num
    if num < min:                   # 最小値を更新する
        min = num
    sum += num                      # 合計値を更新する．

print(f"max: {max}, min: {min}, sum: {sum}, avg: {sum/100}") # 統計値を出力する．

# randoms に格納された乱数値を順に出力する．
for i,r in enumerate(randoms):  # enumerate 関数を使い，インデックスを取得できる．
    print(f"{r:>4}",end="")     # 数値の右寄せは {:>4} で指定する（4桁）
    if i % 10 == 9:             # インデックスを10で割ったときの余りが9のときに開業する
        print("")
