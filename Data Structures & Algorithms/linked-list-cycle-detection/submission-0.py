# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# two pointer algorithm for O(1) space solution
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # slow & fast pointer keep looping until slow meets fast or there is no loop
        # O(n) time solution
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True
        

        return False
        