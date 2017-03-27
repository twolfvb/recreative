class Heap:
    def __init__(self, input_arr=[]):
        self.array = []
        self.size = len(input_arr)
        self.build_max_heap(input_arr)

    def build_max_heap(self, inputArr):
        self.array=inputArr
        if self.heap_size() <= 1:
            return
        for i in range(self.heap_size()/2):
            self.max_heapify(self.heap_size()/2 - i)

    def left(self, i):
        return 2*i

    def right(self, i):
        return 2*i+1

    def parent(self, i):
        return i/2

    def heap_size(self):
        return self.size

    def get_key(self, i):
        return self.array[i-1][0]

    def __str__(self):
        return str(self.array)

    def swap(self, a, b):
        aux = self.array[a-1]
        self.array[a-1] = self.array[b-1]
        self.array[b-1] = aux

    def max_heapify(self, i):
        left = self.left(i)
        right = self.right(i)
        if left <= self.heap_size() and self.get_key(left) > self.get_key(i):
            largest = left
        else:
            largest = i
        if right <= self.heap_size() and self.get_key(right) > self.get_key(largest):
            largest = right
        if largest != i:
            self.swap(largest, i)
            self.max_heapify(largest)

    def heap_sort(self, input_arr):
        self.build_max_heap(input_arr)
        for i in range(len(input_arr), 0, -1):
            self.swap(1, i)
            self.size -= 1
            self.max_heapify(1)


h = Heap([[4,"root"], [1, "a"], [3, "a"], [2, "a"], [16, "a"], [9, "a"], [10, "a"], [14, "a"], [8, "a"], [7, "a"]])

inputarr = h.array
print h
h.heap_sort(inputarr)
print h
