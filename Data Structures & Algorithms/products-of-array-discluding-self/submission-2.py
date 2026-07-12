class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefixArr = [1 for i in range(len(nums))]
        prefix = 1

        for i in range(len(nums)):
            prefixArr[i] = prefix
            prefix *= nums[i]
        
        postfixArr = [1 for i in range(len(nums))]
        postIndex = len(nums) - 1
        postfix = 1

        while postIndex >= 0:
            postfixArr[postIndex] = postfix
            postfix *= nums[postIndex]
            postIndex -= 1
        
        returnArray = [1 for i in range(len(nums))]
        for i in range(len(nums)):
            returnArray[i] = prefixArr[i] * postfixArr[i]

        return returnArray

        