test = [74,85,69,77,81]
above_eighty = []
count = 0
print("test scores:",test)

avg = sum(test)/len(test)
print("max:",max(test))
print("min:",min(test))
print("avg:",avg)

print("sorted ascending:",sorted(test))
print("sorted descending:",sorted(test,reverse= True))

for t in test:
    if t >= 80:
        above_eighty.append(t)
        count += 1
print("above 80 scores:",above_eighty)
print("number of people above 80:", count)