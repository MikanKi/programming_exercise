#454403 フェリシア・アイヴィー
import sys

def find_age(age, low, high, step = 1):
    mid = (low + high) // 2
    if mid == age:                              # age を当てたら
        return step                             # step を返す
    elif mid < age:                             # mid が age より小さい場合
        return find_age(age,mid+1,high,step+1)  # find_age の範囲をmid+1から始める
    else:                                       # そうでない場合
        return find_age(age,low,mid,step+1)     # find_age の範囲をmidで終わる

for age_string in sys.argv[1:]:
    age = int(age_string)
    step = find_age(age, 0, 100)
    print(f'age = {age}, step = {step}')
