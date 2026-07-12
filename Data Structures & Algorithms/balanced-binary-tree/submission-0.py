# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        balanced = True

        def heightRec(root):
            nonlocal balanced
            if root == None:
                return 0
            
            l = heightRec(root.left)
            r = heightRec(root.right)

            if abs(l - r) > 1:
                balanced = False
            
            if l > r:
                return l + 1
            
            return r + 1

        heightRec(root)
        return balanced

        