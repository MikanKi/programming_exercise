months = [1,2,3,4,5,6,7,8,9,10,11,12]
month_names = ["jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"]

list = [1,2,3]
a, b, c = list
print(a)
print(b)
print(c)

for num, m in zip(months, month_names):
    print(f"{m} ( {num} 月)")

print()

for i,m in enumerate(month_names):
    print(f"{m} ( {i+1} 月)")

myTuple = ["John", "Peter", "Vicky"]

x = "#".join(myTuple)

print(x)