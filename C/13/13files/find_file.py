#!/usr/bin/env python3
# -*- coding : UTF-8 -*-

# find_file.py
# 指定された名前のファイルを指定されたディレクトリ以下から探して表示する

import sys
import os

# name という名前のファイルを base 以下から探して表示する
def find_file(name, base):
    # base がディレクトリの場合
    if os.path.isdir(base):
        # base の一覧を取得し，それぞれを処理する．
        for item in os.listdir(base):
            # パス名にする
            path = os.path.join(base, item)
            # find_file を再帰的に呼び出す．
            find_file(name, path)
    # そうでない場合
    else:
        filename = os.path.basename(base) # base から ファイル名部分を取り出す．
        # filename が name と一致する場合
        if filename == name:
            print(f"{base}")   # 結果を表示

# メイン
for base in sys.argv[2:]:   # 2つ目以降の引数が探す対象のディレクトリ
    find_file(sys.argv[1], base)   # 1つ目の引数は探すファイル名
