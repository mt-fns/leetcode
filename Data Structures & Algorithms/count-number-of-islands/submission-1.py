class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROW = len(grid)
        COL = len(grid[0])

        counter = 0

        def dfs(r, c):
            grid[r][c] = "0"
            adj = [[-1, 0], [0, -1], [1, 0], [0, 1]]

            for k, l in adj:
                nr = r + k
                nc = c + l

                if nr < 0 or nc < 0 or nr >= ROW or nc >= COL:
                    continue
                
                if grid[nr][nc] == "1":
                    dfs(nr, nc)

        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == "1":
                    dfs(i, j)
                    counter += 1

        
        return counter
