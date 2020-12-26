class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
    
    def __str__(self):
        return str(self.data)

class LinkedList:
    def __init__(self, head = None):
        self.head = head
        self.size = 0
    
    def append(self, data):
        current = self.head
        while current.next != None:
            current = current.next
        current.next = Node(data, None)
        self.size += 1
    
    def __str__(self):
        s = ''
        ptr = self.head
        while ptr:
            s += str(ptr)+' '
        return s

    def sort(self):
        for i in range(self.size-1):
            cur = self.head
            nxt = cur.next
            prev = None
            while nxt:
                if cur.data > nxt.data:
                    if prev == None:
                        prev = cur.next
                        nxt = nxt.next
                    
                        prev.next = cur
                        cur.next = nxt
                        self.head = prev
                    else:
                        temp = nxt 
                        nxt = nxt.next
                        prev.next = cur.next
                        prev = temp

                        temp.next = cur
                        cur.next = nxt
                else:
                    prev = cur
                    cur = nxt
                    nxt = nxt.next
            i = i+1

lst = LinkedList()

lst.append(5)
lst.append(10)
lst.append(2)
lst.append(1)
lst.append(39)
lst.append(11)

print(lst)

        
    