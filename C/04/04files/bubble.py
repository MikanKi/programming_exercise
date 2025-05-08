#!/usr/bin/env python3
# -*- coding : UTF-8 -*-
# bubble.py
# バブルソートの実装例（Pythonバージョン）

data = [7, 5, 1, 2, 8, 3]  # ソート対象データ

# データを表示（ソート前）
print("ソート前:", " ".join(map(str, data)))

# バブルソートの処理
size = len(data)
for k in range(1, size):
    for j in range(size - 1, k - 1, -1):
        print(j, end=" ")  # デバッグ用
        if data[j] < data[j - 1]:  # 隣同士を比較
            data[j], data[j - 1] = data[j - 1], data[j]  # 値を入れ替える
print()  # デバッグ用

# データを表示（ソート後）
print("ソート後:", " ".join(map(str, data)))

