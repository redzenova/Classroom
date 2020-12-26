
#Noamal 
def BinarySerach(array, x , low ,high):
    while low <= high:

        mid = (high + low)//2

        if array[mid] == x:
            return mid
        elif array[mid] < x:
            low = high + 1
        else:
            high = mid - 1
    return -1

#Recursive
def BinarySerachRe(array, x , low , high):
    if high > low:

        mid = (low + high)//2

        if array[mid] < x :
            BinarySerachRe(array, x , low, mid + 1)
        elif array[mid] > x:
            BinarySerachRe(array, x , mid - 1 , high)
        else:
            return True
    return False

inp = input('Enter Array for serch : ').split('|')
arr , x = list(map(int, inp[0].split())), int(inp[1])
print(BinarySerachRe(arr, x , 0, len(arr) - 1))