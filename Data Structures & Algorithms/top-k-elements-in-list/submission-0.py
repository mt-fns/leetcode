class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        frequency = []

        # initialize frequency array, index is number of frequency
        # with arrays of numbers with the same frequency in the same index
        for i in range(len(nums) + 1):
            frequency.append([])

        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1
        
        # key value pair in count hash
        for num, freq in count.items():
            frequency[freq].append(num)
        
        topKElements = []
        kCount = 0
        for i in range(len(frequency)):
            if kCount >= k:
                break
            
            lastIndex = len(frequency) - 1
            currFreq = frequency[lastIndex - i]
            
            # iterate from the back
            # check if a number exist with this frequency
            if len(currFreq) > 0:
                for num in currFreq:
                    if kCount < k:
                        topKElements.append(num)
                        kCount += 1
                    else:
                        break
        
        return topKElements




        