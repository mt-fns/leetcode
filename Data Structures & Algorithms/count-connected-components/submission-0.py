class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjMap = {}
        visited = set()
        numComponent = 0

        for i in range(n):
            adjMap[i] = []

        for edge in edges:
            adjMap[edge[0]].append(edge[1])
            adjMap[edge[1]].append(edge[0])

        def dfs(node, prev):
            if node in visited:
                return
        
            visited.add(node)

            for nei in adjMap[node]:
                dfs(nei, node)

            return

        for i in range(n):
            if i not in visited:
                numComponent += 1
                dfs(i, -1)
        
        return numComponent
            

            





        