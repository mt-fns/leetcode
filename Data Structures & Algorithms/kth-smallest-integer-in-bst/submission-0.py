# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # in order traversal and store each node value in an array element
        # kth smallest would be in array[k]
        values = []

        def inOrderRec(root):
            nonlocal values
            if root == None:
                return
            
            inOrderRec(root.left)
            values.append(root.val)
            inOrderRec(root.right)
        
        inOrderRec(root)
        return values[k - 1]