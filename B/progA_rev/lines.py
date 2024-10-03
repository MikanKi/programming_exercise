#454403　フェリシア・アイヴィー
import sys

for filename in sys.argv[1:]: 
    with open(filename,"r") as f: # ファイルを読み込む
        line_num = len(f.readlines()) # 行数を読み取る
    print(line_num,filename)
