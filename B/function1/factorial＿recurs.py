#454403 フェリシア・アイヴィー  

import sys

def factorial(n,initial):
    if n == initial:
        fact = n
    fact *= (n-1)
    n -= 1
    if n == 1:
        return fact
    else:
        factorial(n,initial)

for arg in sys.argv[1:]:
    n = int(arg)
    print(f"{n}! = {factorial(n,n)}")
