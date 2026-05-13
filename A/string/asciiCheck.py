string = input()
string_list = list(string)
print(string_list)
alpha = 0
number = 0
other = 0

for s in string_list:
    if (s >= "A" and s <= "Z") or (s >= "a" and s <= "z"):
        alpha += 1
    elif (s >= "0" and s <= "9"):
        number += 1
    else:
        other += 1
print("alpha =",alpha,"number =",number,"other =",other)
