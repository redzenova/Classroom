def bubbleSort(arr):
    count = 0
    for i in range(len(arr)-1):
        swapValue = None
        has_swaped = False
        for j in range(len(arr)-i-1):
            if arr[j] > arr[j+1]:
                #swap
                swapValue = arr[j]
                arr[j], arr[j+1] = arr[j+1] , arr[j]
                has_swaped =True
                
        count+=1
        if has_swaped == False or i==len(arr)-2:
            print(f'last step : {arr}',end=' ')
            print(f'move[{swapValue}]')
            return
        else:
            print(f'{count} step : {arr}',end=' ')
            print(f'move[{swapValue}]')


inp = list(map(int,input("Enter Input : ").split()))
bubbleSort(inp)