dict1 = {"one":1,"two":2,"three":3,"four":4,"five":5}

for key in dict1.keys():
    print(key,dict1[key])

for value in dict1.values():
    print(value)

for key, value in dict1.items():
    print(key,value)
