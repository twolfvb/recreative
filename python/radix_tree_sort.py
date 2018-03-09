class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class RadixTree:
    def __init__(self):
        self.root = None

    def insert(self, item):
        self.root = self.insert_rec(self.root, item, 0)

    def insert_rec(self, root, item, index):

        if index == len(item):

            if root is None:
                return TreeNode(item)

            root.value = item
            return root

        if root is None:
            root = TreeNode(None)

        if item[index] == '0':
            root.left = self.insert_rec(root.left, item, index + 1)
        else:
            root.right = self.insert_rec(root.right, item, index + 1)
        return root

    def return_sorted(self):
        self.sortedvals = []
        self.pushSorted(self.root)
        return self.sortedvals

    def pushSorted(self, root):
        if root is None:
            return
        if root.value is not None:
            self.sortedvals.append(root.value)
        self.pushSorted(root.left)
        self.pushSorted(root.right)


def sort_strings(strs):
    radix_tree = RadixTree()
    for s in strs:
        radix_tree.insert(s)
    return radix_tree.return_sorted()


print sort_strings(['1101', '11', '011', '00', '1100'])
