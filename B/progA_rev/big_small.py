#454403　フェリシア・アイヴィー
import random

num = random.randint(1, 10) # 1 以上 10 以下の乱数を生成する．

print(num)
if num >=5:
    # num が 5 以上なら Big
    print("Big")
else:
    # 5 未満なら Small を出力する．
    print("Small")
