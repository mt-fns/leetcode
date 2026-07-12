class Solution:
    # have a hash set for each row and column then go for 3x3 scans
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        colSets = [set() for i in range(len(board))]
        rowSets = [set() for i in range(len(board[0]))]

        # do 3x3 block scans
        currRow = 0
        currCol = 0

        while currRow < len(board):    

            subBoxSet = set()
            for i in range(3):
                for j in range(3):
                    currVal = board[currRow + i][currCol + j]
                    if currVal != ".":
                        currVal = int(currVal)
                        if currVal in subBoxSet or currVal in colSets[currCol + j] or currVal in rowSets[currRow + i]:
                            return False
                        else:
                            subBoxSet.add(currVal)
                            colSets[currCol + j].add(currVal)
                            rowSets[currRow + i].add(currVal)
            currCol += 3
            if currCol >= len(board):
                currCol = 0
                currRow += 3  
        
        return True


        