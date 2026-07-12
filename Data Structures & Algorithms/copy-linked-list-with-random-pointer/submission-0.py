"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    # two pass O(n) time, O(n) space solution
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # {original: copy}
        copyHash = {None: None}
        if head == None:
            return None

        curr = head

        # iterate through original list, create copy of nodes and map (old: new)
        # in the hash map
        while curr != None:
            copy = Node(curr.val)
            copyHash[curr] = copy
            curr = curr.next
        
        # iterate through original list, link random and next pointers based on hash map
        curr = head

        while curr != None:
            copy = copyHash[curr]
            copy.random = copyHash[curr.random]
            copy.next = copyHash[curr.next]
            curr = curr.next
        
        return copyHash[head]
        


        
        
        

        