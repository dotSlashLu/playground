def qsort(arr):
    if len(arr) < 2:
        return arr
    pivot = arr[0]
    less = [i for i in arr[1:] if i < pivot]
    greater = [i for i in arr[1:] if i >= pivot]
    return qsort(less) + [pivot] + qsort(greater)

print qsort([34,2,6,3,6,8,9,1,0,12,5,643,435,342])
