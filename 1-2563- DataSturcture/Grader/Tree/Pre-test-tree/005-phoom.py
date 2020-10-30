### Class ###
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def getMinNode(self, root):
        current = root
        while current.left is not None:
            current = current.left
        return current

    def getMaxNode(self, root):
        current = root
        while current.right is not None:
            current = current.right
        return current

    def getNodeByValue(self, root,value):
        current = root
        while current is not None:
            if value < current.value:
                current = current.left
            elif value > current.value:
                current = current.right
            else:
                return current

    def insert(self,root,value):
        if root is None:
            return Node(value)

        if value < root.value:
            root.left = self.insert(root.left,value)  
        else:
            root.right = self.insert(root.right,value)

        return root

    def delete(self,root,value):
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
            # Node with [0,1] child
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp

            # Node with [2] child : Use inorder successor
            else:
                # successor = node that cotent smallest value in the right subtree
                successor = self.getMinNode(root.right)

                # Replace root.value with the successor
                root.value = successor.value

                # Delete node that content the successor
                root.right = self.delete(root.right, successor.value)
                
        return root

    def BFS(self, root):
        queue = []
        queue.append(root)
        while len(queue) != 0:
            print(queue[0].value, end=' ')
            if queue[0].left is not None:
                queue.append(queue[0].left)
            if queue[0].right is not None:
                queue.append(queue[0].right)
            queue.pop(0)

    def DFS_preOrder(self, root):
        if root is None:
            return

        print(root.value, end=' ')
        self.DFS_preOrder(root.left)
        self.DFS_preOrder(root.right)

    def DFS_inOrders(self, root):
        if root is None:
            return

        self.DFS_inOrders(root.left)
        print(root.value, end=' ')
        self.DFS_inOrders(root.right)

    def DFS_postOrder(self, root):
        if root is None:
            return

        self.DFS_postOrder(root.left)
        self.DFS_postOrder(root.right)
        print(root.value, end=' ')

    def printTree(self, node, level=0):
        if node is not None:
            self.printTree(node.right, level + 1)
            print('     ' * level, node.value)
            self.printTree(node.left, level + 1)

