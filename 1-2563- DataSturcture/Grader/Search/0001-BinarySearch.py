def BinarySearch(left, right, lst, key):
    if left <= right:
        mid = (left + right) // 2
        if lst[mid] < key:
            return BinarySearch(mid + 1, right, lst, key)
        elif lst[mid] > key:
            return BinarySearch(left, mid - 1, lst, key)
        else:
            return True
    return False


inp = input('Enter Input : ').split('/')
arr, k = list(map(int, inp[0].split())), int(inp[1])

print(BinarySearch(0, len(arr) - 1, sorted(arr), k))
