# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invertRecursive(root):
            if root == None:
                return
            
            tempL = root.left
            root.left = root.right
            root.right = tempL

            invertRecursive(root.right)
            invertRecursive(root.left)
        
        invertRecursive(root)
        return root
        