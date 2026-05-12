year = int(input("年を入力してください。"))
if year % 4 == 0:
    if year % 100 == 0:
        if year % 400 == 0:
            print("YES")
        else:
            print("NO")
    else:
        print("YES")
else:
    print("NO")