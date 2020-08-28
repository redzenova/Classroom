inp = input('Enter number end with (-1) : ').split('-1')

if len(inp) >= 2 :
    inp = inp[0].split()

    dic = {}

    for i in range(len(inp)):
        if inp[i] not in dic:
            dic[inp[i]] = 1
        else:
            dic[inp[i]] +=1

    if max(dic.values()) > len(inp)/2 :
        for j in dic.keys():
            if dic[j] == max(dic.values()):
                print(j)
    else:
        print('Not found')
else:
    print('Invalid INPUT !!!')