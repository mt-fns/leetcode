class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # dfs cycle checking, build out connection array as you go
        adjMap = {i:[] for i in range(len(edges) + 1)}

        # dfs cycle checking
        def dfs(curr, parent):
            if curr in visited:
                return True
            
            visited.add(curr)

            for nei in adjMap[curr]:
                if nei != parent:
                    if dfs(nei, curr):
                        return True
            
            return False

        
        for u, v in edges:
            adjMap[u].append(v)
            adjMap[v].append(u)
            visited = set()

            if dfs(u, -1):
                return [u, v]
            
        return []
