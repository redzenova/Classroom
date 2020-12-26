
def ShellSort(lst, n):
    interval = n//2
    while interval > 0:
        for i in range(interval , n):
            temp = lst[i]
            j = i
            while j >= interval and lst[j - interval] > temp:
                lst[j] = lst[j - interval]
                j -= interval
            lst[j] = temp
        interval //= 2


l = [2,5,6,3,5,8,6,9]
print(l)
size = len(l)
ShellSort(l, size)
print(l)