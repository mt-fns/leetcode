# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # reverse linked lists, loop through both of them
        # keep track of carry overs
        newHead = None
        newCurrent = None
        curr1 = l1
        curr2 = l2
        carryOver = 0

        while curr1 != None or curr2 != None:
            curr1Val = 0
            curr2Val = 0

            if curr1 != None:
                curr1Val = curr1.val
                curr1 = curr1.next
            
            if curr2 != None:
                curr2Val = curr2.val
                curr2 = curr2.next
            
            # check for carry over
            newVal = curr1Val + curr2Val + carryOver
            carryOver = 0

            if newVal > 9:
                newVal = newVal - 10
                carryOver = 1
            
            if newCurrent != None:
                newCurrent.next = ListNode(newVal)
                newCurrent = newCurrent.next
            else:
                newCurrent = ListNode(newVal)
                newHead = newCurrent
        
        # check if carry over requires one more node
        if carryOver > 0:
            newCurrent.next = ListNode(1)
            newCurrent = newCurrent.next

        newCurrent.next = None
    
        return newHead