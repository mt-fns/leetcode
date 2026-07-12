# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        prevNew = None
        currNew = None
        newHead = None
        curr1 = list1
        curr2 = list2

        if list1 == None:
            return list2
        elif list2 == None:
            return list1

        while curr1 != None and curr2 != None:
            if curr1.val < curr2.val:
                currNew = curr1
                curr1 = curr1.next
            else:
                currNew = curr2
                curr2 = curr2.next
            
            if prevNew != None:
                prevNew.next = currNew

            if newHead == None:
                newHead = currNew
            
            prevNew = currNew
        
        if curr1 != None:
            currNew.next = curr1
        elif curr2 != None:
            currNew.next = curr2
        
        return newHead


            

        