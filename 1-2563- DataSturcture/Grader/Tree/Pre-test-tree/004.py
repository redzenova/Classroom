class Node:
    def __init__(self, data):
        self.data = data
        self.left = None 
        self.right = None

    def __str__(self):
        return str(self.data)

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
            return self.root
        else:
            cur = self.root
            while cur is not None:
                if cur.data > data:
                    if cur.left == None:
                        cur.left = Node(data)
                    else:
                        cur = cur.left
                else:
                    if cur.right == None:
                        cur.right = Node(data)
                    else:
                        cur = cur.right
            return self.root
    
    def printTree(self, node, level = 0):
        if node != None:
            self.printTree(node.right, level + 1)
            print(' -->' * level, node)
            self.printTree(node.left , level + 1)

lst = []

def inOrderUntil(node ,n):
    global lst 
    if node != None:
        inOrderUntil(node.left, n)
        if node.data >= n:
            return
        lst.append(str(node.data))
        inOrderUntil(node.right, n)

T = BST()
inp1 , inp2 = input('Enter Input : ').split('|')
inp1 = [int(i) for i in inp1.split()]
inp2 = int(inp2)

for i in inp1:
    root  = T.insert(i)
T.printTree(root)

inOrderUntil(root, inp2)

print('---------------------------------')
print(f'Bellow {inp2} : { "Not have" if lst == [] else " ".join(lst) }')