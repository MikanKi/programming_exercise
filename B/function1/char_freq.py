#454403 フェリシア・アイヴィー

import sys

def count_chars(str):
    # ここに関数を実装してください
    freq = dict()
    for c in str.lower():   #小文字に変換する
        if c in freq:       #文字がディクショナリーにある場合、1を加える
            freq[c] += 1 
        else:               #ない場合、新しいアイテムを作る
            freq[c] = 1 
    return freq             #ディクショナリーを返す

for arg in sys.argv[1:]:
    print(f"{arg}: {count_chars(arg)}")
