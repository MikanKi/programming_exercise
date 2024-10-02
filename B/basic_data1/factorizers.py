# 454403 フェリシア・アイヴィー
import sys

for v in sys.argv[1:]:
    num = int(v)                    # コマンドライン引数を整数に変換する．
    factors = []                    # 素因数を格納するリストを初期化する．
    value = num                     # 素因数分解する値を初期化する．
    factor = 2                      # 素因数
    while factor < value:           # factor が value より小さい間繰り返す．    
        if value % factor == 0:     # value が factor で割り切れたら
            factors.append(factor)  # factor を factors に追加する．
            value /= factor         # value を factor で割り，value に再代入する．
        else:                       # そうでなければ
            factor += 1             # factor を 1 増加させてループを繰り返す．
    if value != 1:                  # ループ後，value が 1 でない場合
        factors.append(int(value))  # value を factors に追加する．

    # 結果を出力する．num を 8桁右寄せで表示する．
    # join は文字列を結合するメソッドで，リストの要素を文字列に変換して，"*" で結合する．
    print(f"{num:>8}: {' * '.join(map(str, factors))}")
