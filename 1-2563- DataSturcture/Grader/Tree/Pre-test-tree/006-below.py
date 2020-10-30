class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
    
    def __str__(self):
        return str(self.value)

class BST:
    def getMin(self, root):
        current = root
        while current.left is not None:
            current = current.left
        return current
    
    def getMax(self, root):
        current = root
        while current.right is not None:
            current = current.right
        return current
    
    def getNodeBtValue(self, root, value):
        current = root
        while current is not None:
            if value < current.value:
                current = current.left
            elif value > current.value:
                current = current.right
            else:
                return current
    
    def insert(self, root, value):
        if root is None:
            return Node(value)
        
        if value < root.value:
            root.left = self.insert(root.left, value)
        else:
            root.right = self.insert(root.right, value)
        
        return root
    
    def delete(self, root, value):
        ### Base Case ###
        if root is None:
            return root
        
        ### Recursion Case ###
        if value < root.value:
            root.left = self.delete(root.left, value)
        if value > root.value:
            root.right = self.delete(root.right, value)

        ### Found Deleted Node ###
        if value == root.value:
            # Node with 0 1 child #
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            
            # Node with 2 child
            else:
                successor = self.getMin(root.right)
                root.value = successor.value
                root.right = self.delete(root.right , successor.value)
        return root
    
    def BFS(self, root):
        q = []
        q.append(root)
        while len(q) != 0:
            print(q[0].values, end='')
            if q[0].left is not None:
                q.append(q[0].left)
            if q[0].right is not None:
                q.append(q[0].right)
            q.pop(0)
    
    def preOrder(self, root):
        if root is None:
            return
        
        print(root.values, end='')
        self.preOrder(root.left)
        self.preOrder(root.right)

    def inOrder(self, root):
        if root is None:
            return
        
        self.inOrder(root.left)
        print(root.values, end='')
        self.inOrder(root.right)

    def postOrder(self, root):
        if root is None:
            return
        
        self.postOrder(root.left)
        self.postOrder(root.right)
        print(root.values, end='')

    def printTree(self , node , level = 0):
        if node is not None:
            self.printTree(node.right, level + 1)
            print(' ->' * level , node.values)
            self.printTree(node.left, level + 1)


T = BST()

T.insert(1)
T.printTree()