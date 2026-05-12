print("整数で入力してください。")
num1 = int(input("num1を入力してください。"))
num2 = int(input("num2を入力してください。"))
answer = num1
if answer < num2:
    answer = num2
print("大きい方は"+str(answer)+"です。")
