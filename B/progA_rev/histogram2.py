#454403　フェリシア・アイヴィー
import matplotlib.pyplot as plt
import sys

data = []

# ファイルを読み込む（sys.argv[1]）
with open(sys.argv[1],"r") as f:
    # ファイルの各行に対して以下を繰り返す．
    for line in f.readlines():
        striped_line = line.strip()     # 読み込んだ行の前後の空白を削除する．
        items = striped_line.split(' ') # 行を空白で分割する．
        loc = int(items[0])             # 行数を整数に変換する．
        #  data に loc を追加する．
        data.append(loc)

# ヒストグラムを描画する．
# - ビン（棒）数を100に設定して，0〜1000行の範囲でヒストグラムを描画する．
plt.hist(data, bins=100, range=(0, 1000))
# - グラフのタイトルを設定する．
plt.title("Lines of Code")
# - ヒストグラムを表示する．
plt.show()
