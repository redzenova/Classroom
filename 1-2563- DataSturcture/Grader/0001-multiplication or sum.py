print("*** multiplication or sum ***")

num1, num2 = input("Enter num1 num2 : ").split()

result = int(num1)*int(num2)

if(result > 1000):
    print("The result is " + str(int(num1)+int(num2)))
else :
    print("The result is " + str(int(num1)*int(num2)))
