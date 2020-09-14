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
    
    def insert(self, index, data):
        return
    
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

n4 = Node('D')
n3 = Node('C', n4)
n2 = Node('B', n3)
n1 = Node('A', n2)

print(n1)
print(n1.next)
print(n1.next.next)
print(n1.next.next.next)

L.append('I')
L.append('J')
L.append('K')
L.append('L')
L.append('A')
L.append('B')
L.append('C')
L.append('D')
L.append('E')
L.append('F')
L.append('G')
L.append('H')


print("Index : " + str(L.indexOf('L')))
print("Value : " + str(L.nodeAt(11)))