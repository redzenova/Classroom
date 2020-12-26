'''
 * กลุ่มที่  : 20010101
 * 62010763 รวีโรจน์ ทองดี
 * chapter : 14	item : 4	ครั้งที่ : 0002
 * Assigned : Friday 9th of October 2020 02:56:28 PM --> Submission : Friday 9th of October 2020 03:42:08 PM	
 * Elapsed time : 45 minutes.
 * filename : 0004.py
'''
class LinkedList:
    class Node :
        def __init__(self,data,next = None) :
            self.data = data
            if next is None :
                self.next = None
            else :
                self.next = next
                
        def __str__(self) :
            return str(self.data)

    def __init__(self,head = None):
        if head == None:
                self.head = self.tail = None
                self.size = 0
        else:
            self.head = head
            t = self.head        
            self.size = 1
            while t.next != None :
                t = t.next
                self.size += 1
            self.tail = t
            
    def __str__(self) :
        s = 'Linked data : '
        p = self.head
        while p != None :
            s += str(p.data)+' '
            p = p.next
        return s

    def __len__(self) :
        return self.size
    
    def append(self, data):
        p = self.Node(data)
        if self.head == None:
            self.head = self.tail = p
        else:
            t = self.tail
            t.next = p   
            self.tail =p  
        self.size += 1

    def removeHead(self) :
        if self.head == None : return
        if self.head.next == None :
            p = self.head
            self.head = None
        else :
            p = self.head
            self.head = self.head.next
        self.size -= 1
        return p.data
    
    def isEmpty(self) :
        return self.size == 0
    
    def nodeAt(self,i) :
        p = self.head
        for j in range(i) :
            p = p.next
        return p

    def contentEquivalence(self, lst):
        count = 0
        n = lst.head
        p = self.head
        if self.size == lst.size:
            while p and n != None :
                    if p.data == n.data:
                        count +=1
                    p = p.next
                    n = n.next

            if count >= self.size:
                return print('List1 content Equivalence List2 : True')
            else:
                return print('List1 content Equivalence List2 : False')
        else:
            return print('List1 content Equivalence List2 : False')
            

inputlist = [e.replace(' ','') for e in input('List1,List2 : ').split(',')]

list1 = LinkedList()
list2 = LinkedList()

lst1 = inputlist[0]
lst2 = inputlist[1]

for i in range(len(inputlist[0])):
    list1.append(lst1[i])
for i in range(len(inputlist[1])):
    list2.append(lst2[i])

list1.contentEquivalence(list2)