text = input("Enter String : ")
num_index = "".join(dict.fromkeys(text))
print('[',end='')

for i in range(len(text)):
    for j in range(len(num_index)):
        if(text[i]==num_index[j]):
            if (i == len(text)-1):
                print(j,end='')
            else:
                print(j,end=', ')

print(']',end='')