#454403 フェリシア・アイヴィー

import sys

def combination(n, k):
    # この中を実装してください．
    if k == 0 or k == n:    # k=0 もしくは k=n であれば、
        return 1            # 1 を返す
    elif n < k:             # もし、n<k であれば、
        return 0            # 0 を返す
    else:                                                   # そうでなければ、
        return combination(n-1,k) + combination(n-1,k-1)    # C(n-1,k) + C(n-1,k-1) を返す

n = int(sys.argv[1])
k = int(sys.argv[2])
print(f'combination({n}, {k}) = {combination(n, k)}')
