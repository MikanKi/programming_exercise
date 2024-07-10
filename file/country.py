import csv

city = input("")

f = open("FEH_00200521_240710100519.csv","r")

rd = csv.reader(f)
r = list(rd)
flag = False

for row in r[14:]:
    if row[7] == city and row[2] == "0" and row[4] == "0":
        flag = True
        num = 1
        sum = 0
        out = [city]
        for n1 in row[10:121]:
            if n1 == "-":
                n1 = "0"
            n2 = n1.replace("," , "")
            sum += int(n2)
            if num%10 == 0 or num == 111:
                out.append(sum)
                sum = 0
            num += 1

if flag:
    print(out)
else:
    print("####ERROR####")
    print(" {} does not exist".format(city))

f.close()

