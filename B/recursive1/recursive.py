def fraction(n):
    if n == 1:
        return 1
    else:
        return n * fraction(n-1)

print(fraction(4))