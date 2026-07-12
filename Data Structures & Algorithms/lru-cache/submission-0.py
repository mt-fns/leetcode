class Node:
    def __init__(self, key=0, val=0, nxt=None, prev=None):
        self.next = nxt
        self.prev = prev
        self.key = key
        self.val = val

class LRUCache:
    # store an array and a double ll
    # keep track of the left-most element in ll (last used element)
    # and the right most element in ll (newly used element)
    # if length > capacity, remove left-most element, and point to the next left-most
    # if get/put is called, update element to be the right-most element
    def __init__(self, capacity: int):
        # cache, {key: Node(key, val)}
        self.keys = {}
        self.capacity = capacity
        self.left = Node()
        self.right = Node()
        self.left.next = self.right
        self.right.prev = self.left

    def remove(self, node):
       prev, nxt = node.prev, node.next
       prev.next = nxt
       nxt.prev = prev

    # insert at right-most
    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        node.prev = prev
        node.next = nxt
        nxt.prev = node
        prev.next = node

    def get(self, key: int) -> int:
        if key in self.keys:
            # update to right-most element
            self.remove(self.keys[key])
            self.insert(self.keys[key])
            return self.keys[key].val
        return -1
       

    def put(self, key: int, value: int) -> None:
        # key already exists, update value (remove node)
        if key in self.keys:
            self.remove(self.keys[key])
        self.keys[key] = Node(key, value)
        self.insert(self.keys[key])

        # capacity exceeded, delete lru cache from ll and hashmap
        if len(self.keys) > self.capacity:
            lru = self.left.next
            self.remove(lru)
            del self.keys[lru.key]

           
           
       



        
