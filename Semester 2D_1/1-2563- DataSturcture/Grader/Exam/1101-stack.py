class Stack:
    def __init__(self, item =None):
        if item is None:
            self.item = []
        else:
            self.item = item
    
    def push(self, item):
        self.item.append(item)
    
    def pop(self):
        return self.item.pop()
    
    def peek(self):
        return self.item[-1]
    
    def size(self):
        return len(self.item)
    
    def isEmpty(self):
        return len(self.item) == 0

    def __str__(self):
        s = ''
        for i in self.item:
            s += str(i)+''
        return s

    def in2pos(self, str):
        operator


def parenMatch(_str):
    s = Stack()
    open_lst = ["(","{","["]
    close_lst = [")","}","]"]

    for i in _str:
        if i in open_lst:
            s.push(i)
        elif i in close_lst:
            pos = close_lst.index(i)
            if s.size() > 0 and s.peek() == open_lst[pos]:
                s.pop()
            else:
                return print('Not Match !')
    
    if s.size() == 0:
        return print('Match !')
    else:
        return print('Not Match !')

inp = list(input('Enter Input : '))
parenMatch(inp)