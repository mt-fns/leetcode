class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # store an array of sets for the column
        # store an array of sets for the row
        # do 3 by 3 scans, storing a set of all elements
        # compare this to the row and column sets
        colSets = []
        rowSets = []

        for i in range(len(board)):
            rowSets.append(set())
            colSets.append(set())
        
        rowCount = 0
        colCount = 0
        for i in range(9):
            gridSet = set()

            if rowCount >= 9:
                rowCount = 0
                colCount += 3

            for j in range(3):
                for k in range(3):
                    currRow = rowCount + j
                    currCol = colCount + k
                    currItem = board[currRow][currCol]
                    if currItem != '.':
                        if currItem in gridSet:
                            return False

                        if currItem in colSets[currCol]:
                            print(j, k, currItem, colSets[k])
                            return False
                        
                        if currItem in rowSets[currRow]:
                            # print(currItem)
                            return False
                        
                        gridSet.add(currItem)
                        colSets[currCol].add(currItem)
                        rowSets[currRow].add(currItem)
            
            rowCount += 3
                
        return True
                      
                        
                
        