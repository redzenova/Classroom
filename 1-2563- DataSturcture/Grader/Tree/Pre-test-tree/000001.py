class Node:
    def __init__(self, value, left=None, right=None):
        self.data = value
        self.left = left
        self.right = right
    
    def __str__(self):
        return str(self.data)

class Stack:
    def __init__(self):
        self.item =[]
    
    def isEmpty(self):
        return len(self.item) == 0
    
    def size(self):
        return len(self.item)

    def push(self, data):
        self.item.append(data)

    def pop(self):
        if not self.isEmpty():
            return self.item.pop()

class Queue:
    def __init__(self):
        self.item = []
    
    def isEmpty(self):
        return len(self.item) == 0
    
    def size(self):
        return len(self.item)
    
    def enQueue(self, data):
        self.item.append(data)
    
    def deQueue(self):
        if not self.isEmpty():
            return self.item.pop(0)

class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        newNode = Node(data)

        if self.root is None:
            self.root = newNode
        else:
            current = self.root
            while current is not None:
                if data > current.data:
                    if current.left is not None:
                        current = current.left
                    else:
                        current.left = newNode
                        return self.root
                else:
                    if current.right is not None:
                        current = current.right
                    else:
                        current.right = newNode
                        return self.root
    
    def delete(self, value):
        if self.root is None:
            return self.root
        
        if value < self.root.data:
            self.root.left = self.delete(self.root.left, value)
        if value > self.root.data:
            self.root.right = self.delete(self.root.right, value)
        
        if value == self.root.data:
            if self.root.left is None:
                temp = self.root.right
                root = None
                return temp
            elif self.root.right is None:
                temp = self.root.left
                root = None
                return temp
        return root
                
    def preOrder(self, root):
        if root is None:
            return
        
        print(root.data, end=' ')
        self.inOrder(root.left)
        self.inOrder(root.right)

    def inOrder(self, root):
        if root is None:
            return
        
        self.inOrder(root.left)
        print(root.data, end=' ')
        self.inOrder(root.right)

    def postOrder(self, root):
        if root is None:
            return
        
        self.inOrder(root.left)
        self.inOrder(root.right)
        print(root.data, end=' ')

    def max(self):
        if self.root is None:
            return
        curr = self.root
        while curr.right is not None:
            curr = curr.right
        return curr.data
    
    def min(self):
        if self.root is None:
            return
        curr = self.root
        while curr.left is not None:
            curr = curr.left
        return curr.data
    


    def printTree(self, node, level = 0):
        if node != None:
            self.printTree(node.right, level + 1)
            print(' -->' * level , node)
            self.printTree(node.left, level + 1)

T = BinarySearchTree()
inp = [int(i) for i in input('Enter Input : ').split()]

print(inp)
for i in inp:
    root = T.insert(i)
T.printTree(root)

print('Min : ', T.max())
print('Max : ', T.min())
T.inOrder(root)
print()
T.preOrder(root)
print()
T.postOrder(root)