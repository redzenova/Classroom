
def ShellSort(lst, n):
    inteval = n//2
    while inteval > 0:
        for i in range(inteval, n):
            temp = lst[i]
            j = i
            while j >= inteval and lst[j - inteval] > temp:
                lst[j] = lst[j - inteval]
                j -= inteval
            lst[j] = temp
        inteval //= 2

def swap(A, i ,j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp


def BubbleSort(A, n):
    for i in range(n-1):
        if A[i] > A[i+1]:
            swap(A, i, i+1)
        if n-1 > 1:
            BubbleSort(A, n-1)


l = [2,5,8,9,4,1,3,5,7]
l2 = [3,5,46,8,1,3,5,6]
print(l)
BubbleSort(l, len(l))
print(l)

print(l2)
ShellSort(l2, len(l2))
print(l2)