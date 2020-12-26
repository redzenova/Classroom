
def BinarySearch(left, right , lst, key):
    if left <= right:
        mid = (left + right) // 2
        if lst[mid] < key:
            return BinarySearch(mid+1, right, lst, key)
        elif lst[mid] > key:
            return BinarySearch(left, mid-1, lst,key)
        else:
            return True
    return False

inp = input('Enter : ').split(]|)