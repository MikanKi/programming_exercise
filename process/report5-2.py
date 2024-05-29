print("整数で入力してください。")
num1 = int(input("num1を入力してください。"))
num2 = int(input("num2を入力してください。"))
num3 = int(input("num3を入力してください。"))
answer = num1
if answer < num2:
    answer = num2
if answer < num3:
    answer = num3
print("最も大きなものは"+str(answer)+"です。")
