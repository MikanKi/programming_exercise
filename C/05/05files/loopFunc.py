#!/usr/bin/env python3
# -*- coding : UTF-8 -*-

# loopFunc.py
# 実行時間の比較（Python版）
# 処理毎に関数に分割したもの（結果表示以外）

import random  # 乱数のライブラリを使うため

MAXCOUNT = 10000000  # ループ回数

# 初期化
def init():
    print("Python: start")

# 乱数を使って処理
def upDown(max):
    count = 0   # 結果を入れる変数。0で初期化

    for i in range(max):
        if random.randint(0, 255) % 2 == 0: # 偶数の場合
            count -= 1                      # 1減らす
        else:                               # 奇数の場合
            count += 1                      # 1増やす

    return count

# メイン
init()                      # 初期化
result = upDown(MAXCOUNT)   # 処理
print(f"num = {result}")    # 結果を出力

