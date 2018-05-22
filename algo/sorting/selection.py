def get_smallest(arr):
    smallest_idx = 0
    smallest = arr[smallest_idx]
    # get the smallest
    for i, elem in enumerate(arr):
        if elem < smallest:
            smallest_idx = i
            smallest = elem
    # swap the smallest to the head
    arr[0], arr[smallest_idx] = smallest, arr[0]
    return [arr[0]], arr[1:]

def select(arr):
    i = 0
    sorted = []
    rest = arr
    while i < len(arr):
        smallest, rest = get_smallest(rest)
        sorted += smallest
        i += 1
    return sorted

arr = [3,6,23,43,54,234,34,12,3,4]
res = select(arr)
print("original arr", arr, " \nordered arr ", res)
