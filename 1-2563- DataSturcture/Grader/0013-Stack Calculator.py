class Calculator  :

    def __init__(self):
        self.item = []

    def run(self, arg):
        arg = arg.split()

        for s in arg:
            if s == 'DUP':
                self.item.append(self.item[-1])
            elif s == 'POP':
                self.item.pop()
            elif s == '+': 
                self.item.append(self.item.pop() + self.item.pop())
            elif s == '-': 
                self.item.append(self.item.pop() - self.item.pop())
            elif s == '*': 
                self.item.append(self.item.pop() * self.item.pop())
            elif s == '/': 
                self.item.append(self.item.pop() // self.item.pop())
            else:
                try:
                    self.item.append(int(s))
                except:
                    print(f'Invalid instruction: {s}')
                    quit()

    def push(self, var):
        self.item.append(var)
    
    def pop(self):
        return self.item.pop()

    def peek(self):
        return self.item[-1]
    
    def size(self):
        return len(self.item)

    def getValue(self):
        return 0 if len(self.item) == 0 else self.item[-1]

print('* Stack Calculator *')
arg = input('Enter arguments : ')
machine = Calculator()
machine.run(arg)
print(machine.getValue())