class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = None if left is None else left
        self.right = None if right is None else right
    
    def __str__(self):
        return str(self.data)

    def getData(self):
        return self.data
    
    def getLeft(self):
        return self.left
    
    def getRight(self):
        return self.right
    
    def setData(self, data):
        self.data = data
    
    def setLeft(self, data):
        self.left = data
    
    def setRight(self, data):
        self.right = data
    
class BST:
    def __init__(self, root = None):
        self.root = None if root is None else root
    
    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            cur = self.root
            while cur is not None:
                if data < cur.data:
                    if cur.left is not None:
                        cur = cur.left
                    else:
                        cur.left = Node(data)
                        return self.root
                else:
                    if cur.right is not None:
                        cur = cur.right
                    else:
                        cur.right = Node(data)
                        return self.root
    
    def printTree(self, node ,level=0):
        if node != None:
            self.printTree(node.right , level + 1)
            print('   -->' * level, node)
            self.printTree(node.left, level + 1)

T = BST()
inp = [int(i) for i in input('Enter Input : ').split()]
for i in inp:
    root = T.insert(i)
T.printTree(root)