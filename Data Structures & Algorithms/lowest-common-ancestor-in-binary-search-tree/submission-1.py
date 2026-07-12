# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # check if p and q are children of current nodes
        # as soon as the first node with p and q as their children is found, return it
        lowestCommon = None

        def searchValue(root, x):
            if root == None:
                return False
            
            if root.val == x.val:
                return True
            
            l = searchValue(root.left, x)
            r = searchValue(root.right, x)
            return l or r

        def lowestCommonRec(root, p, q):
            # check if p == q
            # if current root == p, check if q is a child of root and vice versa
            # if yes, return curren true and update lowestCommon
            # if not, return true
            nonlocal lowestCommon
            if root == None:
                return False
            
            print(root.val)

            if root.val == p.val:
                print("test")
                # p is the lowest common
                if searchValue(root, q):
                    lowestCommon = root
                    return False
                return True
        
            if root.val == q.val:
                print("test")
                # q is the lowest common
                if searchValue(root, p):
                    lowestCommon = root
                    return False
                return True
            
            l = lowestCommonRec(root.left, p, q)
            r = lowestCommonRec(root.right, p, q)

            if l and r and lowestCommon == None:
                lowestCommon = root
                return False
            
            return l or r

        lowestCommonRec(root, p, q)
        return lowestCommon

           