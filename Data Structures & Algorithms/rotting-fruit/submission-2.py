class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        step = 0
        fresh = 0
        ROW = len(grid)
        COL = len(grid[0])
        neighbors = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    q.append((i, j))
        
        while q and fresh > 0:
            for _ in range(len(q)):
                row, col = q.popleft()
                for nei in neighbors:
                    nr = row + nei[0]
                    nc = col + nei[1]

                    if nr < 0 or nc < 0 or nr >= ROW or nc >= COL:
                        continue
                    
                    if grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh -= 1
                        q.append((nr, nc))
            step += 1
    
        if fresh > 0:
            return -1
        
        return step








