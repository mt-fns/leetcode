class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hashSet = set(nums)
        longest = 0

        for i in nums:
            prev = i - 1
            length = 0
            # this is a starting point
            if prev not in hashSet:
                while prev + 1 in hashSet:
                    length += 1
                    prev += 1
            
            if length > longest:
                longest = length
        
        return longest
            


