# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        # two functions, one to loop through all nodes in root until it finds
        # a node that matches subRoot
        # if a match is found, loop through all nodes in subRoot and compare with root
        subtree = False

        def findRootRec(root, subRoot):
            nonlocal subtree
            if root == None or subRoot == None:
                return
            
            if root.val == subRoot.val:
                subtree = checkSubRootRec(root, subRoot)
                if subtree:
                    return

            findRootRec(root.left, subRoot)
            findRootRec(root.right, subRoot)

        def checkSubRootRec(root, subRoot):
            if root == None and subRoot == None:
                return True
            if root == None or subRoot == None:
                return False
            if root.val != subRoot.val:
                return False
            
            l = checkSubRootRec(root.left, subRoot.left)
            r = checkSubRootRec(root.right, subRoot.right)

            return l and r

        findRootRec(root, subRoot)
        return subtree