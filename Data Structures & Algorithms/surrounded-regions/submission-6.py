class Solution:
    def solve(self, board: List[List[str]]) -> None:
        # update all unsurrounded regions to a temp value, say T
        N_ROW = len(board)
        N_COL = len(board[0])
        neighbors = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        def dfs(row, col):
            board[row][col] = "T"

            for nei in neighbors:
                n_row = row + nei[0]
                n_col = col + nei[1]
                if n_row < 0 or n_col < 0 or n_row >= N_ROW or n_col >= N_COL:
                    continue
                
                if board[n_row][n_col] == "O":
                    board[n_row][n_col] = "T"
                    dfs(n_row, n_col)

        for r in range(N_ROW):
            if board[r][0] == "O":
                dfs(r, 0)

            if board[r][N_COL - 1] == "O":
                dfs(r, N_COL - 1)
        
        for c in range(N_COL):
            if board[0][c] == "O":
                dfs(0, c)

            if board[N_ROW - 1][c] == "O":
                dfs(N_ROW - 1, c)
        
        
        for i in range(N_ROW):
            for j in range(N_COL):
                if board[i][j] == "T":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
        
        
        
        