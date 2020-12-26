print(' ***  Perfect Number Verification ***')
n = int(input('Enter number : '))

if n < 1:
    print('Only positive number !!!')
    quit()

fac = [1]

for i in range(2, n):
    if n % i == 0:
        fac.append(i)

if sum(fac) == n :
    print(str(n) + ' is a PERFECT NUMBER.')
else:
    print(str(n) + ' is NOT a perfect number.')

print('Factors :', fac)