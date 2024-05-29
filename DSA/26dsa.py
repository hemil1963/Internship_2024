class Node:
    def __init__(self, value):
        self.data = value
        self.next = None
        self.prev = None


class Deque:
    def __init__(self):
        self.front = None
        self.rear = None

    def is_empty(self):
        return self.front is None

    def push_front(self, value):
        new_node = Node(value)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node
        
    def push_back(self, value):
        new_node = Node(value)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.prev = self.rear
            self.rear.next = new_node
            self.rear = new_node
        
    def pop_front(self):
        if self.is_empty():
            print("Deque is empty. Cannot pop from the front.")
            return

        temp = self.front
        self.front = self.front.next
        if self.front:
            self.front.prev = None
        else:
            self.rear = None

        

    def pop_back(self):
        if self.is_empty():
            print("Deque is empty. Cannot pop from the back.")
            return

        temp = self.rear
        self.rear = self.rear.prev
        if self.rear:
            self.rear.next = None
        else:
            self.front = None

        

    def get_front(self):
        if self.is_empty():
            print("Deque is empty. Cannot get front element.")
            return None
        return self.front.data

    def get_back(self):
        if self.is_empty():
            print("Deque is empty. Cannot get back element.")
            return None
        return self.rear.data



d = Deque()

d.push_front(1)
d.push_back(2)
d.push_front(3)

print(f"Front: {d.get_front()}, Back: {d.get_back()}")

d.pop_front()
d.pop_back()

print(f"Front: {d.get_front()}, Back: {d.get_back()}")
