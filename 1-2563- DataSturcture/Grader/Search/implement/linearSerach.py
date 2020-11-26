# LinearSearch or Unordered Searching
#  + Sentinel Search : 
#  + Move to Front :
#  + Transposition :

def linearSearch(array, n, x):
    for i in range(0, n):
        if (array[i] == x):
            return i
    return -1

l = [2,6,5,1,8,9]