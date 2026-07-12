class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # do bfs until closest chest is found
        #
        # keep track of visited list so we dont keep revisiting
        # the same nodes
        #
        # increase step as bfs layer go -> each step to clear layer,
        # keep track of len of queue

        INF = 2147483647
        ROW, COL = len(grid), len(grid[0])
        neighbors = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        def bfs(r, c):
            visited = [[False] * COL for _ in range(ROW)]
            q = deque()
            visited[r][c] = True
            q.append((r, c))

            dist = 0

            while q:                
                for _ in range(len(q)):
                    row, col = q.popleft()

                    if grid[row][col] == 0:
                        return dist

                    for neigh in neighbors:
                        nr = row + neigh[0]
                        nc = col + neigh[1]

                        if nr < 0 or nc < 0 or nr >= ROW or nc >= COL:
                            continue
                        
                        if visited[nr][nc]:
                            continue
                        
                        if grid[nr][nc] >= 0:
                            visited[nr][nc] = True
                            q.append((nr, nc))
                dist += 1

            return INF
                    
        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == INF:
                    grid[i][j] = bfs(i, j)

        