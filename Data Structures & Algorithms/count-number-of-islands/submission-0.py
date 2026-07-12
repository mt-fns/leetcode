class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS = len(grid)
        COLUMNS = len(grid[0])
        neighbors = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        num = 0

        def bfs(r,c):
            q = deque()
            q.append((r,c))
            grid[r][c] = "0"

            while q:
                r, c =  q.popleft() 

                # check all neighbors
                for neighbor in neighbors:
                    dr = r + neighbor[0]
                    dc = c + neighbor[1]

                    if dr < 0 or dc < 0 or dr >= ROWS or dc >= COLUMNS:
                        continue
                    
                    if grid[dr][dc] == "1":
                        q.append((dr,dc))
                        grid[dr][dc] = "0"

        for r in range(ROWS):
            for c in range(COLUMNS):
                if grid[r][c] == '1':
                    # island found, bfs all possible nodes
                    bfs(r, c)
                    num += 1

        return num
            

        