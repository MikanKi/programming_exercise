#454403 フェリシア・アイヴィー

import sys

def fibonacci(n):
    if n>2:                                     # n>2 であれば、
        return fibonacci(n-1) + fibonacci(n-2)  # fibonacci(n-1) + fibonacci(n-2) を返す
    else:                                       # n=1 または n=2 であれば、
        return 1                                # 1 を返す

for arg in sys.argv[1:]:
    n = int(arg)
    print(f'fibonacci({n}) = {fibonacci(n)}')
