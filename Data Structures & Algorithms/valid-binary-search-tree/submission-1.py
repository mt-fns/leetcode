# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # keep track of parent node as well as comparing if left and right 
    # is valid

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validRec(root, leftBound, rightBound):
            if root == None:
                return True
            
            if root.val <= leftBound or root.val >= rightBound:
                return False
            
            return validRec(root.left, leftBound, root.val) and validRec(root.right, root.val, rightBound)
            
        
        return validRec(root, float("-inf"), float("inf"))
        
        