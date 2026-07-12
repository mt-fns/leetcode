# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        if root == None:
            return res

        nodeQueue = collections.deque()
        nodeQueue.append(root)

        while nodeQueue:
            qLen = len(nodeQueue)
            for i in range(qLen):
                node = nodeQueue.popleft()

                # make sure that no NULL nodes gets added to queue
                if node.left:
                    nodeQueue.append(node.left)
                if node.right:
                    nodeQueue.append(node.right)

                # last element in level - rightmost element
                if i == (qLen - 1) and node:
                    res.append(node.val)
        
        return res

        