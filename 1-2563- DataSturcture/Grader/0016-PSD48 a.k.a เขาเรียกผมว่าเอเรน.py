class Queue:

    def __init__(self):
        self.queue = []

    def __str__(self):
        return  ', '.join(str(data) for data in self.queue) if self.size() != 0 else 'Empty'
    
    def enQueue(self, item):
        self.queue.append(item)
    
    def deQueue(self):
        return self.queue.pop(0) if self.size() != 0 else 'Empty'

    def size(self):
        return len(self.queue)

    def insert(self,index,item):
        self.queue.insert(index,item)
    

lst = input('Enter Input : ').split(',')
q = Queue()
index = 0

for i in lst:
    i = i.split()
    if i[0] == 'EN':
        q.enQueue(i[1])
    elif i[0] == 'ES':
        q.insert(index,i[1])
        index += 1
    elif i[0] == 'D':
        if index != 0:
            index -= 1
        print(q.deQueue())