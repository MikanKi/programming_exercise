import sys

days_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# 月と日が与えられたとき，1月1日からの日数を返す関数
def month_day_to_int(month, day):
    days = 0
    for i in range(month - 1):
        days += days_of_month[i]
    return days + day

# 1〜365 が与えられたとき，月と日を返す関数
def int_to_month_day(n):
    for i in range(12):
        if n <= days_of_month[i]:
            return i + 1, n
        n -= days_of_month[i]

def find_birthday(month, day, low, high, step = 1):
    mid = (low + high) // 2
    if mid == month_day_to_int(month,day):                  
        return step
    elif mid < month_day_to_int(month,day):
        return find_birthday(month,day,mid+1,high,step+1)
    else:
        return find_birthday(month,day,low,mid,step+1)


month = int(sys.argv[1])
day = int(sys.argv[2])
step = find_birthday(month, day, 1, 365)
print(f'birthday = {month}/{day}, step = {step}')

# 以下，テストコード
assert month_day_to_int(1, 1) == 1
assert month_day_to_int(2, 1) == 32
assert month_day_to_int(12, 31) == 365

assert int_to_month_day(1) == (1, 1)
assert int_to_month_day(60) == (3, 1)
assert int_to_month_day(365) == (12, 31)
