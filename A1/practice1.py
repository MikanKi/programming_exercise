limit = 11
primes = []

for num in range(2, limit+1):
    flag = True
    for n in range(2,num):
        if num % n == 0:
            flag = False
            break
    if flag:
        primes.append(num)

print(primes)
