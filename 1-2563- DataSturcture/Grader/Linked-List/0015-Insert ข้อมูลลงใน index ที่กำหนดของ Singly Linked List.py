class Node:
    def __init__(self, data, next = None):
        self.data = data
        if next == None:
            self.next = None
        else:
            self.next = next
    
    def __str__(self):
        return self.data

class LinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    def __str__(self):
        if self.isEmpty():
            return 'List is empty'
        cur = self.head
        s = "link list : " + str(self.head.data) + "->"
        while cur.next != None:
            s += str(cur.next.data) + "->"
            cur = cur.next
        s = s[:-2]
        return s

    def isEmpty(self):
        return self.head == None

    def __len__(self):
        return self.size

    def append(self, item):
        self.size += 1
        if self.isEmpty():
            self.head = Node(item)
            return
        node = self.head
        while node.next != None:
            node = node.next
        node.next = Node(item)
   
    def insertBefore(self, index, data):
        # create new node
        newNode = Node(data)
        # find target node to insert
        ptr_node = self.nodeAt(index)
        if ptr_node == None:
            print('Data cannot be added')
        else:
            if index == 0 :
                 newNode.next = self.head
                 self.head = newNode
            else:
                newNode.next = ptr_node
                self.nodeAt(index-1).next = newNode
            self.size += 1
    
    def indexOf(self, data):
        q = self.head
        for i in range(len(self)):
            if q.data == data:
                return i
            q = q.next
        return -1
    
    def nodeAt(self, index):
        p = self.head
        for j in range(0, index):
            p = p.next
        return p


L = LinkedList()

inp = input('Enter Input : ').split(',')
addList_ = inp[0].split()
addVal_ = [item.replace(" ","").split(':') for item in inp[1:]]

for i in range(len(addList_)):
    L.append(addList_[i])

print(L)

for i in range(len(addVal_)):
    if int(addVal_[i][0]) == L.size:
        L.append(int(addVal_[i][1]))
        print(f'index = {addVal_[i][0]} and data = {addVal_[i][1]}')
    elif int(addVal_[i][0])>L.size or int(addVal_[i][0])<0:
        print('Data cannot be added')
    else:
        L.insertBefore(int(addVal_[i][0]), int(addVal_[i][1]))
        print(f'index = {addVal_[i][0]} and data = {addVal_[i][1]}')
    print(L)