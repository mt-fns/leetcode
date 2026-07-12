class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def dfs(i, subset):
            if i >= len(nums):
                result.append(subset.copy())
                return

            subset.append(nums[i])
            dfs(i + 1, subset)
        
            # why doesnt this work????
            subset.pop()
            dfs(i + 1, subset)


        dfs(0, [])
        return result
        