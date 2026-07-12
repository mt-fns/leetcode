class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # add all elements inside of the array into a max heap
        # pop twice, if there is a remainder, store the remainder and pop once
        # else pop twice 

        # in order to use min heap as max heap, turn all values in array to negative
        for i in range(len(stones)):
            stones[i] = -stones[i]

        # turn stones array into a max heap (min heap but mimics a max heap)
        heapq.heapify(stones)

        while len(stones) > 1:
            first = heapq.heappop(stones) 
            second = heapq.heappop(stones)
            remainder = first - second

            # add this back to the max heap
            if abs(remainder) > 0:
                heapq.heappush(stones, remainder)

        # remainder left
        if len(stones) > 0:
            res = heapq.heappop(stones)
            return abs(res)
        
        return 0


