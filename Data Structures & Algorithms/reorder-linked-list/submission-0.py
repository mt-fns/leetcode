# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # find mid point using fast and slow pointers
        fast = head.next
        # slow is mid point
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        # set mid node's next to none
        curr = slow.next
        prev = slow.next = None


        # reverse all nodes after mid point
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        # merge linked list with 2 pointers
        l = head
        r = prev

        while r:
            tempR = r.next
            tempL = l.next

            l.next = r
            r.next = tempL

            r = tempR
            l = tempL
    
        