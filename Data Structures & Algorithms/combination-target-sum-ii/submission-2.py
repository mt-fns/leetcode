class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backTrack(i, prev, total):
            if total == target:
                res.append(prev.copy())
                return
            
            if total > target or i >= len(candidates):
                return
            
            prev.append(candidates[i])
            backTrack(i + 1, prev, total + candidates[i])

            prev.pop()
            while (i + 1) < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1

            backTrack(i + 1, prev, total)

        backTrack(0, [], 0)
        return res
        