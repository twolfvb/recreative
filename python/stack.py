class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

    def get_value(self):
        return self.val

    def get_next(self):
        return self.next


class Stack:
    def __init__(self):
        self.top = None

    def push(self, val):
        self.top = Node(val, self.top)

    def pop(self):
        if self.top is None:
            raise Exception("StackUnderflow")
        value = self.top.get_value()
        self.top = self.top.get_next()
        return value

a = Stack()
a.push(1)
a.push(2)
a.push(3)
print a.pop()
print a.pop()
a.push("wat")
print a.pop()
print a.pop()
