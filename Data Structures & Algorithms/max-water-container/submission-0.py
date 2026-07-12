class Solution:
    def maxArea(self, heights: List[int]) -> int:
        # two pointer, scan from left to right and keep track of maximum volume
        # move pointer that has the lower height - keep the other pointer the same
        # O(n) solution
        maxVol = 0
        left = 0
        right = len(heights) - 1

        for i in range(len(heights)):
            if left == right:
                break

            currVol = (right - left) * min(heights[left], heights[right])

            if currVol > maxVol:
                maxVol = currVol
            
            if heights[left] > heights[right]:
                right -= 1
            elif heights[left] < heights[right]:
                left += 1
            else:
                left += 1
        
        return maxVol

