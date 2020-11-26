
#Sort
#  [+] Bubble sort
#  + Selection Sort
#  + Insertion Sort
#  + Shell Sort
#  + Merge Sort
#  + Quick Sort

#Noamal for Loop - Implement
def BubbleSort(lst):
    for last in range(len(lst)-1, -1, -1):
        swaped = False
        for i in range(last):
            if lst[i] > lst[i+1]:
                lst[i] , lst[i+1] = lst[i+1], lst[i]
                swaped = True
        if not swaped:
            break


#Recursive - Implement
def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def BubbleSortRe(A, n):
    for i in range(n-1):
        if A[i] > A[i+1]:
            swap(A, i , i+1)
    if n - 1 > 1:
        BubbleSortRe(A, n-1)



l = [5,4,3,6,9,8,1,2]

print(l)
BubbleSortRe(l, len(l))
print(l)