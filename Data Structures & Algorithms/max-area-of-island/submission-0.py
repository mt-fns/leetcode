class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # bfs -> mark node as zero as we go
        # keep track of number of nodes in the current island
        ROWS, COLS = len(grid), len(grid[0])
        neighbors = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        def bfs(r, c):
            area = 0
            q = deque()
            q.append((r, c))
            grid[r][c] = 0
            area += 1

            while q:
                row, col = q.popleft()

                for neighbor in neighbors:
                    nr = row + neighbor[0]
                    nc = col + neighbor[1]
                    if nr < 0 or nc < 0 or nr >= ROWS or nc >= COLS:
                        continue
                    
                    if grid[nr][nc] == 1:
                        q.append((nr, nc))
                        grid[nr][nc] = 0
                        area += 1
            
            return area

        maxArea = 0

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    area = bfs(i, j)
                    if area > maxArea:
                        maxArea = area
        
        return maxArea
               


        