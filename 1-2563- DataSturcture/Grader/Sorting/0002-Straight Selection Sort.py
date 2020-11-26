
# ========= Normal Selection Sort ===========
# def selectionSort(arg):
#     for i in range(len(arg)):
#         #find minimum value 
#         min_idx = i
#         for j in range(i+1 , len(arg)):
#             if arg[min_idx] > arg[j]:
#                 min_idx = j
        
#         #swap
#         arg[i] , arg[min_idx] = arg[min_idx] , arg[i]
        
# def minIdx(arg , i,j):
#     if i == j:
#         return i
    
#     k = minIdx(arg, i + 1, j)
#     return (i if arg[i] < arg[k] else k)

# def selectionSort(arg , n, index = 0):

#     # berak case : when size are same
#     if index == n:
#         return -1
    
#     k = minIdx(arg , index , n-1)

#     #swap
#     if k != index:
#         print('swap ', end='')
#         arg[k], arg[index] = arg[index], arg[k]

#     #recursive call for sort
#     selectionSort(arg , n ,index + 1)


def selectionSort(sequence, pass_num=None):
    if pass_num is None:
        pass_num = len(sequence)-1

    if pass_num == 0:
        return

    processInPass(sequence, pass_num)
    selectionSort(sequence, pass_num-1)

def processInPass(sequence, pass_num, maxValue_index=0, index=0):
    if index == pass_num + 1:
        if maxValue_index != pass_num:
            sequence[pass_num], sequence[maxValue_index] = sequence[maxValue_index], sequence[pass_num]
            print(
                "swap {} <-> {} : {}".format(sequence[maxValue_index], sequence[pass_num], sequence))
        return

    if sequence[maxValue_index] < sequence[index]:
        maxValue_index = index

    if index < len(sequence):
        processInPass(sequence, pass_num, maxValue_index, index+1)


inp = list(map(int,input("Enter Input : ").split()))
selectionSort(inp)
print(inp)