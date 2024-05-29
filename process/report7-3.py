number = int(input())
count = 0
prime = True
for i in range(2, number):
    print("check", i, end="")
    if number % i == 0:
        print(" は約数", end="")
        count += 1
        prime = False
    print()
print("約数の個数は", count)
if prime is False:
    print(number,"は素数ではない。")
else:
    print(number,"は素数です。")