class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # have a min heap, keep popping until k
        heapq.heapify(nums)

        for i in range(len(nums) - k):
            heapq.heappop(nums)
        
        return heapq.heappop(nums)