#454403 フェリシア・アイヴィー

import sys
import os

# name という名前のファイルを base 以下から探す関数．
# 複数見つかる場合もありうるため，見つかったものをリストで返す．
def find_file(name, base, result = None):
    if result is None:
        result = []
    if os.path.isdir(base):                 # base がディレクトリの場合
        for item in os.listdir(base):       # base の一覧を取得し，それぞれを処理する．
            path = os.path.join(base,item)  # それぞれのアイテムに対して，base と item を join する．
            find_file(name,path,result)     # find_file を再起的に呼び出す．
    elif os.path.isfile(base):              # そうでない場合
        filename = os.path.basename(base)   # base から ファイル名部分を取り出す．
        if filename == name:                # base が name と一致する場合
            result.append(base)             # result に base を追加する．
    return result

for base in sys.argv[2:]:
    paths = find_file(sys.argv[1], base)
    if paths:
        print(f"{sys.argv[1]}: {paths}")
