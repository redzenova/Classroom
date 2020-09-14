print("*** Fun with countdown ***")
txt = input("Enter List : ")
num = txt.split()
num = [int(e) for e in num]
count = 0
add = 0
itr = 1
countdown = [[]] 
i = 0
for e in num :
    if num[i] == 1 :
        countdown[0].append([])
        x = countdown[0]
        addcountdown = x[add]
        count +=1
        j = i
        while num[j] == itr :
            addcountdown.insert(0,num[j])
            j-=1
            itr+=1 
        itr = 1
        add += 1
    i+=1
countdown.insert(0,count)
print(countdown)