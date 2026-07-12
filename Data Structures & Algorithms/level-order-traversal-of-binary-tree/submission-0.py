# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # use queue -> [[value, depth]]
        # keep track of depth as recursive calls happen
        nodeQueue = []
        res = []

        def levelOrderRec(root, depth):
            nonlocal nodeQueue
            if root == None:
                return
            
            nodeQueue.append((root.val, depth))
            levelOrderRec(root.left, depth + 1)
            levelOrderRec(root.right, depth + 1)
        
        levelOrderRec(root, 0)
        for node in nodeQueue:
            val = node[0]
            depth = node[1]

            if (len(res) <= depth):
                res.append([])
            
            res[depth].append(val)
        
        return res
            


        