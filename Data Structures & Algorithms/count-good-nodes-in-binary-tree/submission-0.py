# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0

        if root == None:
            return 0

        def countGoodNodesRec(root, maxVal):
            nonlocal count
            if root == None:
                return
            
            if root.val >= maxVal:
                count += 1
                maxVal = root.val
            
            countGoodNodesRec(root.left, maxVal)
            countGoodNodesRec(root.right, maxVal)

        countGoodNodesRec(root, root.val)
        return count

        