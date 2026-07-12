class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        window = len(s1)
        s1Characters = {}

        left = 0
        right = window - 1
        pointer = left

        for char in s1:
            if char in s1Characters:
                s1Characters[char] += 1
            else:
                s1Characters[char] = 1
        
        copy = s1Characters.copy()

        while right < len(s2):
            if (right - pointer) < 0:
                return True 

            curr = s2[pointer]
            if curr not in s1Characters or s1Characters[curr] == 0:
                left += 1
                right += 1
                pointer = left
                s1Characters = copy.copy()

            else:
                s1Characters[curr] -= 1
                pointer += 1
        
        return False
        