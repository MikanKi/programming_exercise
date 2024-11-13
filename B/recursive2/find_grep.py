#454403 フェリシア・アイヴィー

import sys
import os

# file_path というファイルに keyword が含まれているかを判定する関数
# 含まれていれば True を返し，そうでなければ False を返す．
def contains_keyword(file_path, keyword):
    with open(file_path,"r") as f:  # file_path を読み込みモードで開く．
        for line in f.readlines():  # ファイルを一行ずつ読み込む．
            if keyword in line:     # line に keyword が含まれているかを判定する．
                return True         # 含まれていれば True を返す．
            else:                   # 含まれていなければ False を返す．
                return False

# name という名前のファイルを base 以下から探す関数．
# 複数見つかる場合もありうるため，見つかったものをリストで返す．
def find_grep(keyword, base, result = None):
    if result is None:
        result = []
    if os.path.isdir(base): # base がディレクトリの場合
        # base の一覧を取得し，それぞれを処理する．
        for child in os.listdir(base):
            if not child.startswith("."):           # 隠しファイルは対象外とする．
                path = os.path.join(base,child)     # それぞれのアイテムに対して，base と child を join する．
                find_grep(keyword, path, result)    # find_grep を再起的に呼び出す．
    if os.path.isfile(base):                # そうでない場合
        if contains_keyword(base, keyword): # base に keyword が含まれているかを判定する．
            result.append(base)             # result に base を追加する．
    return result

for base in sys.argv[2:]:
    paths = find_grep(sys.argv[1], base)
    if paths:
        print(f"{sys.argv[1]}: {paths}")
