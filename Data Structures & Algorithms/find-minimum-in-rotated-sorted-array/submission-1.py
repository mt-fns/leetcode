class Solution:
    # [5,6,0,1,2,3,4]

    def findMin(self, nums: List[int]) -> int:
        # binary search: until mid is less than both left and right
        # mid > left, new left = mid
        # else new right = mid
        left = 0
        right = len(nums) - 1
        midVal = 1001
        
        while (left + 1) < right:
            mid = (left + right) // 2
            if nums[left] < nums[mid] < nums[right]:
                return nums[left]
            
            if nums[left] > nums[mid] > nums[right]:
                return nums[right]

            if nums[mid] > nums[left]:                    
                left = mid
            
            elif nums[mid] < nums[right]:
                right = mid
        
        return min(nums[left], nums[right])


        
