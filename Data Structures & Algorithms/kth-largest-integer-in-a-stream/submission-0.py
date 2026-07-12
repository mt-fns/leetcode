class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.minHeap = nums
        self.k = k
        # turn array to minHeap
        heapq.heapify(self.minHeap)

        # keep the kth largest elements in the min heap by popping all 
        # of the other elements less than
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)

        # if min heap has less than k elements
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)

        # return smallest element in the heap of k largest elements
        return self.minHeap[0]