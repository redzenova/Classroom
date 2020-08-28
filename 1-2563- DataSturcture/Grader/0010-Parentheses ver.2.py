class Stack:

    def __init__(self, lst = None):
        if lst == None:
            self.item = []
        else:
            self.item = lst
    
    def push(self, i):
        self.item.append(i)
    
    def pop(self):
        return self.item.pop()

    def peek(self):
        return self.item[-1]

    def isEmpty(self):
        return self.item == []

    def sizeIs(self):
        return len(self.item)

    def __str__(self):
        s = ''
        for i in self.item:
            s += str(i)+''
        return s

def parenMaching(tx):
    s = Stack()
    open_list = ["[","{","("]
    close_list = ["]","}",")"]

    for i in tx:
        if i in open_list:
            s.push(i)
        elif i in close_list:
            pos = close_list.index(i)
            if s.sizeIs() > 0 and s.peek() == open_list[pos]:
                s.pop()
            else:
                return print('Parentheses : Unmatched ! ! !')
    if s.sizeIs() == 0:
        return print('Parentheses : Matched ! ! !')
    else:
        return print('Parentheses : Unmatched ! ! !')

### My code
inp = list(input('Enter Input : '))
parenMaching(inp)
