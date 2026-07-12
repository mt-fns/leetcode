# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        same = True

        def checkRec(pRoot, qRoot):
            nonlocal same
            if pRoot == None and qRoot == None:
                return
            
            if pRoot == None or qRoot == None:
                same = False
                return
        
            if pRoot.val != qRoot.val:
                same = False
                return
            
            checkRec(pRoot.left, qRoot.left)
            checkRec(pRoot.right, qRoot.right)
        
        checkRec(p, q)
        return same
            