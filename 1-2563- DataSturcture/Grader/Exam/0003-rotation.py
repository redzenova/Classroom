print(' *** String Rotation ***')

inp = input('Enter 2 string : ').split()

temp = inp
count = 0
print(temp)

while True:
    if count < 5:
        print(count+1, temp[0][-2] + temp[0][-1] + temp[0][:-2], temp[1][-3] + temp[1][-2] + temp[1][-1] + temp[1][:-3])

    temp = (temp[0][-2] + temp[0][-1] + temp[0][:-2]+' '+ temp[1][-3] + temp[1][-2] + temp[1][-1] + temp[1][:-3]).split(' ')
    count +=1
    
    if temp == inp:
        break
    if count > 5:
        print('..........')
        print(count+1, temp[0][-2] + temp[0][-1] + temp[0][:-2], temp[1][-3] + temp[1][-2] + temp[1][-1] + temp[1][:-3])

print(f'Total of {count} rounds.')