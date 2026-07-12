# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        newHead = None

        while curr != None:
            # end of list, new head
            if curr.next == None:
                curr.next = prev
                newHead = curr
                break
            
            temp = curr.next
            curr.next = prev

            prev = curr
            curr = temp

        return newHead



        