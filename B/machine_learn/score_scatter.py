#454403 フェリシア・アイヴィー
import sys
import matplotlib.pyplot as plt

def open_csv(filename):
    x = []
    y = []
    with open(filename, 'r') as f:
        f.readline()    # ヘッダ行を読み飛ばす．
        for line in f:
            cols = line.strip().split(",") # 改行を削除し，コンマで分割する．
            x.append(float(cols[2]))    # 試験の点数（2列目, float）を x に追加する．
            y.append(float(cols[3]))    # 最終課題（3列目, float）の点数を y に追加する．
    return x, y

x, y = open_csv(sys.argv[1]) # コマンドライン引数のファイルを読み込む．
plt.rcParams["font.family"] = "Hiragino Maru Gothic Pro" # フォントをヒラギノ丸ゴシックに設定する．
plt.title('試験と最終課題の散布図')
plt.xlabel("試験の点数")
plt.ylabel("最終課題の点数")
plt.axis("equal") # グラフの縦横比を 1:1 にする．
plt.scatter(x,y)    # x, y の散布図を描画する．
plt.show()
