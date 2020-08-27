class MyInt:

    def __init__(self, num):
        self.num = num
        self.is_prime = False
        self.list_prime = list()

        for i in range(2, self.num+1):
            n = 2
            while n <= i ** 0.5:
                if i % n == 0:
                    break
                n +=1
            else:
                self.list_prime.append(i)
                if i == self.num:
                    self.is_prime = True
    
    def isPrime(self):
        return self.is_prime
    
    def showPrime(self):
        print(f'Prime number between 2 and {self.num} : ', end = '')
        if self.num < 2:
            print('!!!A prime number is a natural number greater than 1')
            return 0
        for a in self.list_prime:
            print(a, end = " ")
        print()

    def __sub__(self, b):
        print(f'{self.num} - {b} = {self.num - (b // 2)}')


print(' *** class MyInt ***')
x, y = map(int, input('Enter 2 number : ').split())

a = MyInt(x)
b = MyInt(y)
print(f'{x} isPrime :', a.isPrime())
print(f'{y} isPrime :', b.isPrime())
a.showPrime()
b.showPrime()
a.__sub__(y)