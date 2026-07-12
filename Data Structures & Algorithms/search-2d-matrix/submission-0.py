class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # go to the middle index of the matrix and check the first element
        # if > move left pointer to mid + 1
        # if < move right pointer to mid - 1
        # do this until first element < target and last checked > target or target found
        # if target not found, look at the row of the current checked and perform binary search
        leftRow = 0
        rightRow = len(matrix) - 1

        # find row where number should be
        while leftRow <= rightRow:
            midRow = int((leftRow + rightRow) // 2)
            if matrix[midRow][0] < target: 
                leftRow = midRow + 1
            elif matrix[midRow][0] > target:
                rightRow = midRow - 1
            else:
                return True
        
        leftCol = 0
        rightCol = len(matrix[0]) - 1

        while leftCol <= rightCol:
            midCol = int((leftCol + rightCol) / 2)
            if matrix[rightRow][midCol] < target: 
                leftCol = midCol + 1
            elif matrix[rightRow][midCol] > target:
                rightCol = midCol - 1
            else:
                return True
        
        return False

        
        