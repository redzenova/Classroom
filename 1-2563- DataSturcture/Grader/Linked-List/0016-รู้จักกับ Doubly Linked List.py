class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.previous = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def __str__(self):
        if self.isEmpty():
            return "Empty"
        cur, s = self.head, str(self.head.value) + " "
        while cur.next != None:
            s += str(cur.next.value) + " "
            cur = cur.next
        return s

    def reverse(self):
        if self.isEmpty():
            return "Empty"
        cur, s = self.tail, str(self.tail.value) + " "
        while cur.previous != None:
            s += str(cur.previous.value) + " "
            cur = cur.previous
        return s

    def isEmpty(self):
        return self.head == None

    def append(self, item):
        self.size += 1
        if self.isEmpty():
            self.head =Node(item)
            return
        ptr = self.head
        while ptr.next != None:
            ptr = ptr.next
        node = Node(item)
        ptr.next = node
        node.previous = ptr


    def addHead(self, item):
        self.insert(0, item)

    def insert(self, pos, item):
        # create new node
        newNode = Node(item)
        # find target node to insert
        ptr_node = self.nodeAt(pos)
        if ptr_node == None:
            print('Data cannot be added')
        else:
            if pos == 0 :
                 newNode.next = self.head
                 self.head = newNode
            else:
                newNode.next = ptr_node
                newNode.previous = self.nodeAt(pos-1)
                self.nodeAt(pos-1).next = newNode
            self.size += 1

    def search(self, item):
        p = self.head
        for j in range(0, item):
            p = p.next
        return p

    def index(self, item):
        q = self.head
        for i in range(len(self)):
            if q.data == data:
                return i
            q = q.next
        return -1

    def size(self):
        return self.size

    def __len__(self):
        return self.size
    
    def nodeAt(self, index):
        p = self.head
        for j in range(0, index):
            p = p.next
        return p

    def pop(self, pos):
        p = self.head
        for j in range(0, pos):
            p = p.next
        return p.value

L = LinkedList()
inp = input('Enter Input : ').split(',')
for i in inp:
    if i[:2] == "AP":
        L.append(i[3:])
    elif i[:2] == "AH":
        L.addHead(i[3:])
    elif i[:2] == "SE":
        print("{0} {1} in {2}".format(L.search(i[3:]), i[3:], L))
    elif i[:2] == "SI":
        print("Linked List size = {0} : {1}".format(L.size(), L))
    elif i[:2] == "ID":
        print("Index ({0}) = {1} : {2}".format(i[3:], L.index(i[3:]), L))
    elif i[:2] == "PO":
        before = "{}".format(L)
        k = L.pop(int(i[3:]))
        print(("{0} | {1}-> {2}".format(k, before, L)) if k == "Success" else ("{0} | {1}".format(k, L)))
    elif i[:2] == "IS":
        data = i[3:].split()
        L.insert(int(data[0]), data[1])
print("Linked List :", L)
print("Linked List Reverse :", L.reverse())