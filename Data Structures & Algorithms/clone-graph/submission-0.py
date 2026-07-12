"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        cloneMap = {}

        def dfs(node):
            if node in cloneMap:
                return cloneMap[node]
            
            copy = Node(node.val)
            cloneMap[node] = copy
            
            for neighbor in node.neighbors:
                cloneMap[node].neighbors.append(dfs(neighbor))

            return cloneMap[node]
        
        if node == None:
            return None
        
        return dfs(node)