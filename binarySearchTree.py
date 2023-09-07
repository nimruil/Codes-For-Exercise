// Python implementation

class Node:
    def __init__(self,key):
        self.val = key
        self.left = None
        self.right = None

def Insert(root, key):
    nodeToAdd = Node(key)
    currentNode = root
    previousNode = None

    while currentNode != None:
        previousNode = currentNode
        if nodeToAdd.val < currentNode.val:
            currentNode = currentNode.left
        else:
            currentNode = currentNode.right

    if previousNode.val > nodeToAdd.val:
        previousNode.left = nodeToAdd
        print(str(nodeToAdd.val) + ", was added to the left of " + str(previousNode.val))
    else:
        previousNode.right = nodeToAdd
        print(str(nodeToAdd.val) + ", was added to the right of " + str(previousNode.val))

def Search(root,key):
    currentNode = root
    print("Search order: ")
    keyFound = True

    while currentNode.val != key:
        print(str(currentNode.val) + " -> ", end ="")
        if key < currentNode.val:
            currentNode = currentNode.left
        else:
            currentNode = currentNode.right
        if currentNode == None:
            keyFound = False
            print("Sayi agacta mevcut degil")
            break

    if currentNode != None:
        print(currentNode.val)
    if keyFound:
        print("Number exists on tree.")

def print_tree(root, val="val", left="left", right="right"):
    def display(root, val=val, left=left, right=right):
        """Returns list of strings, width, height, and horizontal coordinate of the root."""
        # No child.
        if getattr(root, right) is None and getattr(root, left) is None:
            line = '%s' % getattr(root, val)
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if getattr(root, right) is None:
            lines, n, p, x = display(getattr(root, left))
            s = '%s' % getattr(root, val)
            u = len(s)
            first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s
            second_line = x * ' ' + '/' + (n - x - 1 + u) * ' '
            shifted_lines = [line + u * ' ' for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if getattr(root, left) is None:
            lines, n, p, x = display(getattr(root, right))
            s = '%s' % getattr(root, val)
            u = len(s)
            first_line = s + x * '_' + (n - x) * ' '
            second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
            shifted_lines = [u * ' ' + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = display(getattr(root, left))
        right, m, q, y = display(getattr(root, right))
        s = '%s' % getattr(root, val)
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s + y * '_' + (m - y) * ' '
        second_line = x * ' ' + '/' + (n - x - 1 + u + y) * ' ' + '\\' + (m - y - 1) * ' '
        if p < q:
            left += [n * ' '] * (q - p)
        elif q < p:
            right += [m * ' '] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * ' ' + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2

    lines, *_ = display(root, val, left, right)
    for line in lines:
        print(line)

valueArray = [3,5,6,7,9,8,13,17,16,19,18,20,1]
root = Node(15)
print("Root and members taken from code")
print("Root = " + str(root.val))
for x in range(len(valueArray)):
    Insert(root,valueArray[x])
input = 13
print("Value to search = " + str(input))
Search(root,input)
print("")
print("BST View")
print("")
print_tree(root)
