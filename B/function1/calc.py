#454403 フェリシア・アイヴィー

import sys

def calc(value1, operator, value2):
    # ここに関数を実装してください
    if operator == "+":             #足し算の場合、足し算する
        result = value1 + value2
    elif operator == "-":           #引き算の場合、引き算する
        result = value1 - value2
    elif operator == "*":           #掛け算の場合、掛け算する
        result = value1 * value2    
    elif operator == "/":           #割り算の場合、割り算する
        result = value1 / value2
    else:                           #違う演算子の場合、エラーのメッセージを返す
        result = "not a valid operator"
    # operator の値に応じて，value1 と value2 の演算結果を返します．
    return result

if len(sys.argv) != 4:
    print('Usage: python3 calc.py <value1> <operator> <value2>')
    sys.exit(1)
value1 = int(sys.argv[1])
operator = sys.argv[2]
value2 = int(sys.argv[3])
print(calc(value1, operator, value2))
