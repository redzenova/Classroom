def ShellSort(lst, n):
    interval = n//2
    while interval > 0:
        for i in range(interval,n):
            temp = lst[i]
            j = i
            while j >= interval and lst[j - interval] > temp:
                lst[j] = lst[j - interval]
                j -= interval

            lst[j] = temp
        interval //= 2
