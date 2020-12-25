def ShellSort(lst, n):
    inteval = n // 2
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

def BubbleSort()        