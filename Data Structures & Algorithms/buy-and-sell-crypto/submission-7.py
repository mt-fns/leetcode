class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # left and right pointer, right starts one day after left
        # if right < left, change left to right and right += 1
        # keep track of max profit

        maxProf = 0
        left = 0
        right = 1

        while right < len(prices):
            currProf = prices[right] - prices[left]
            if currProf > maxProf:
                maxProf = currProf

            if prices[right] < prices[left]:
                left = right

            right += 1
        
        return maxProf