class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numHash = {}

        for i in range(len(nums)):
            numHash[nums[i]] = i
        
        for i in range(len(nums)):
            numCompliment = target - nums[i]

            if numCompliment in numHash:
                if i == numHash[numCompliment]:
                    continue
                return [i, numHash[numCompliment]]
        
        return []

        