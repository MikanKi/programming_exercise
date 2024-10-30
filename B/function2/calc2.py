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

#足し算のテスト
assert calc(0,"+",0)  == 0, "Error: 0 + 0 != 0"
assert calc(0,"+",1)  == 1, "Error: 0 + 1 != 1"
assert calc(23,"+",46)  == 69, "Error: 23 + 46 != 69"
assert calc(-2,"+",-2)  == -4, "Error: -2 + -2 != -4"
assert calc(3,"+",-5)  == -2, "Error: 3 + -5 != -2"

#引き算のテスト
assert calc(0,"-",0)  == 0, "Error: 0 - 0 != 0"
assert calc(1,"-",0)  == 1, "Error: 1 - 0 != 1"
assert calc(0,"-",1)  == -1, "Error: 0 - 1 != -1"
assert calc(-1,"-",0)  == -1, "Error: -1 - 0 != -1"
assert calc(0,"-",-1)  == 1, "Error: 0 - -1 != 1"
assert calc(100,"-",31)  == 69, "Error: 100 - 31 != 69"
assert calc(5,"-",3)  == 2, "Error: 5 - 3 != 2"
assert calc(2,"-",6)  == -4, "Error: 2 - 6 != -4"
assert calc(-7,"-",2)  == -9, "Error: -7 - 2 != -9"
assert calc(3,"-",-9)  == 12, "Error: 3 - -9 != 12"
assert calc(-5,"-",-8)  == 3, "Error: -5 - -8 != 3"
assert calc(-8,"-",-5)  == -3, "Error: -8 - -5 != -3"

#掛け算のテスト
assert calc(0,"*",0)  == 0, "Error: 0 * 0 != 0"
assert calc(0,"*",1)  == 0, "Error: 0 * 1 != 0"
assert calc(0,"*",-1)  == 0, "Error: 0 * -1 != 0"
assert calc(3,"*",23)  == 69, "Error: 3 * 23 != 69"
assert calc(-3,"*",4)  == -12, "Error: -3 * 4 != -12"
assert calc(-5,"*",-6)  == 30, "Error: -5 * -6 != 30"

#割り算のテスト
assert calc(0,"/",1)  == 0, "Error: 0 / 1 != 0"
assert calc(1,"/",1)  == 1, "Error: 1 / 1 != 1"
assert calc(-1,"/",2)  == -0.5, "Error: -1 / 2 != -0.5"
assert calc(138,"/",2)  == 69, "Error: 138 / 2 != 69"
assert calc(6,"/",3)  == 2, "Error: 6 / 3 != 2"
assert calc(4,"/",16)  == 0.25, "Error: 4 / 16 != 0.25"
assert calc(-3,"/",9)  == -1/3, "Error: -3 / 9 != 0.333"
assert calc(12,"/",-4)  == -3, "Error: 12 / -4 != -3"
assert calc(-5,"/",-25)  == 0.2, "Error: -5 / -25 != 0.2"
assert calc(-60,"/",-6)  == 10, "Error: -60 / -6 != 10"
