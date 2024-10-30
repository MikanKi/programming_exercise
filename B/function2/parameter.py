

def sum_range(until,start = 1):
    if start>until:
        return 0
    sum = 0
    for i in range(start,until+1):
        sum += i
    return sum

print(sum_range(2,6))