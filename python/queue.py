class Node:
    def __init__(self, val=None, nextNode=None):
        self.val = val
        self.nextNode = nextNode

    def get_val(self):
        return self.val

    def get_next(self):
        return self.nextNode

    def __str__(self):
        return "[ " + str(self.val) + " ] -> " + str(self.nextNode)


class Queue:
    def __init__(self):
        self.first = None
        self.last = self.first

    def enqueue(self, val):
        if self.first is None:
            self.first = Node(val, None)
            self.last = self.first
        else:
            self.last.nextNode = Node(val, None)
            self.last = self.last.nextNode

    def dequeue(self):
        if self.first is None:
            raise Exception("Cannot dequeue empty queue")
        value = self.first.get_val()
        self.first = self.first.nextNode
        return value

    def __str__(self):
        return "primero de la cola -> " + str(self.first) + " <- ultimo en la cola"

a = Queue()
a.enqueue(1)
a.enqueue(2)
a.enqueue(3)
a.enqueue(4)
a.enqueue(5)
print a
print a.dequeue()
print a.dequeue()
print a.dequeue()
print a.dequeue()
print a