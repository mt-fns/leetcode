class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # secretly a leetcode hard - floyd's algorithm for cycle detection
        slow, fast = 0, 0

        # find initial intersection
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        # find start of cycle using 2 slow pointers
        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                break
        
        return slow
        

        


        
        