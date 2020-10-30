class Node:
    def __init__(self, value, left =None, right = None):
        self.data = value
        self.left = len
        self.right = right
    
    def __str__(self):
        return str(self.data)


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
    def Min(self):
        if self.root is None:
            return
        cur = self.root
        while cur.left is not None:
            cur = cur.left
        return cur.data
 

    def preOrder(self, root):
        if self.root is None:
            return
        
        print(root.data , end=' ')
        self.preOrder(root.left)
        self.preOrder(root.right)

    def printTree(self, node, level = 0):
        if node != None:
            self.printTree(node.right, level + 1)
            print(' ->' * level, node)
            self.printTree(node.left, level + 1)
        