# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        longest = 0

        def depthBinaryTree(root):
            nonlocal longest

            if root == None:
                return 0
            else:
                leftDepth = depthBinaryTree(root.left)
                rightDepth = depthBinaryTree(root.right)

                if (leftDepth + rightDepth) > longest:
                    longest = leftDepth + rightDepth
                
                if leftDepth > rightDepth:
                    return leftDepth + 1
                
                return rightDepth + 1
        
        depthBinaryTree(root)
        return longest
        