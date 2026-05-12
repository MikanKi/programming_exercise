text = input()

f = open(text, "r")
lines = f.readlines()
f.close()
counts = [0]*11

for line in lines:
    words = line.split()
    for word in words:
        length = len(word)
        if length >= 10:
            length = 10
        counts[length] += 1

print("len count |")
for i in range(1,11):
    print("{0:>2}{1:>5}   | {2}".format(i,counts[i],"*"*counts[i]))
