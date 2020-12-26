
def ShellSort(lst, n):
    interval = n//2
    while interval > 0:
        for i in range(interval, n):
            temp = lst[i]
            j = i
            while j >= interval and lst[j - interval] > temp:
                #swap
                lst[j] = lst[j - interval]
                j -= interval
            lst[j] = temp
        interval //= 2

l = [2,5,6,3,7,9,5,3]
print(l)
ShellSort(l, len(l))
print(l)