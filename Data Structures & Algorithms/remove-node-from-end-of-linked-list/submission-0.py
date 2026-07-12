# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        curr = head

        while curr != None:
            length += 1
            curr = curr.next
        
        prev = None
        curr = head
        currIndex = 0
        target = length - n

        while curr != None:
            if currIndex == target:
                # remove head
                if prev == None:
                    head = head.next
                else:
                    prev.next = curr.next
                    curr.next = None
                break

            prev = curr
            curr = curr.next
            currIndex += 1
        
        return head
