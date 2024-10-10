#454403 フェリシアアイヴィー

import sys # コマンドライン引数を受け取るためのライブラリ

dic = {}   # 単語の出現回数を格納する辞書

with open(sys.argv[1], "r") as f:
    for line in f.readlines():  # ファイルを1行ずつ読み込む
        line = line.strip()     # 改行文字を取り除く（strip）．
        words = line.split()    #スペースで分割する.
        for word in words:      # 各単語を順番に調べる．
            if word in dic:     # 単語が辞書にあれば，
                dic[word] += 1  # カウントを1増やす．
            else:               # なければ，
                dic[word] = 1   # 1を代入する．

print(dic)
