#!/usr/bin/env python3
# -*- coding : UTF-8 -*-
# 実行時間の比較（Python版）
# loop.py

import random  # 乱数のライブラリを使うため

MAXCOUNT = 100000000  # ループ回数(1億回)
count = 0   # 結果を入れる変数。0で初期化

print("Python: start")

for i in range(MAXCOUNT):
    if random.randint(0, 255) % 2 == 0: # 偶数の場合
        count -= 1                      # 1減らす
    else:                               # 奇数の場合
        count += 1                      # 1増やす

print(f"num = {count}")
