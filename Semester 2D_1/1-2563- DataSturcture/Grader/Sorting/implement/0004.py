def ShellSort(lst, n):
    inteval = n//2
    while inteval > 0:
        for i in range(inteval, n):
            temp = lst[i]
            j = i
            while j >= inteval and lst[j - inteval] > temp:
                lst[j] = lst[j-inteval]
                j -= inteval
            lst[j] = temp
        inteval //= 2


l = [2,6,5,7,9,5,3]
print(l)
ShellSort(l, len(l))
print(l)