"""
 じゃんけん判定をする
 グー:1 チョキ:2 パー:3 とする。
 入力は二つの数字を入れる（最初に自分の手、次に相手の手）
 1 2 は自分がグー、相手がチョキなので、自分の「勝ち」と出せばよい
 """
me = int(input())
you = int(input())

# ここに自分のプログラムを書く
# ここに自分のプログラムを書く
# ここに自分のプログラムを書く
if me == you:
    print("even1")
elif you == me+1 or (me == 3 and you == 1):
    print("win1")
else:
    print("lose1")

diff = (me-you+3) % 3
if diff == 0:
    print("even2")
elif diff == 2:
    print("win2")
else:
    print("lose2")
 # 今は常に win と出すプログラムになっている

