class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adjMap = {}
        visited = set()

        for i in range(n):
            adjMap[i] = []

        # undirected
        for edge in edges:
            adjMap[edge[0]].append(edge[1]) 
            adjMap[edge[1]].append(edge[0]) 

        def dfs(node, prev):
            if node in visited:
                return False
            
            visited.add(node)

            for neighbor in adjMap[node]:
                if neighbor == prev:
                    continue
                if not dfs(neighbor, node):
                    return False
            return True

        return dfs(0, -1) and len(visited) == n
        