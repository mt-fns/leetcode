class Solution:
    # [-1,0,1,2,-1,-4]
    # [-4,-1,-1,0,1,2]

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # sort array
        # problem becomes 2sum
        # use 2 pointer approach on the 2sum problem
        nums.sort()
        ret = []
        
        for i in range(len(nums)):
            # nums[i] is a duplicate value, avoid
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # start l at i + 1 to avoid duplicates
            l = i + 1
            r = len(nums) - 1

            while l < r:
                if nums[l] + nums[r] + nums[i] == 0:
                    ret.append([nums[l], nums[r], nums[i]])
                    # keep going until left pointer points to a value that is not a duplicate
                    l += 1
                    while nums[l] == nums[l - 1]:
                        l += 1

                        # duplicate value until the end of nums array, return current ret array
                        if l >= len(nums):
                            return ret

                elif nums[l] + nums[r] + nums[i] < 0:
                    l += 1

                elif nums[l] + nums[r] + nums[i] > 0:
                    r -= 1

        return ret