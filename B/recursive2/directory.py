def binary_search(list,target,start=0,end=-1):
    if end == -1:
        end = len(list)-1
    if start >= end:
        return -1
    mid = (start + end) // 2
    if list[mid] == target:
        return mid
    elif list[end] == target:
        return end
    elif list[mid] < target:
        return binary_search(list,target,mid,end)
    else:
        return binary_search(list,target,start,mid)

list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

assert binary_search(list, 'd') == 3, f"{list}中のインデックス 3 の要素が 'd' であるはず．"

print(binary_search(list, 'z'))
