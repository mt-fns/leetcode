class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # have a sliding window of len(s1), keep track of 
        # all characters within the current window's count
        # in a hash map, compare current hash map with s1's 
        # hash map to see if current window is a permutation of s1
        s1Hash = {}
        for char in s1:
            if char not in s1Hash:
                s1Hash[char] = 1
            else:
                s1Hash[char] += 1
        
        left = 0
        right = len(s1)

        while right <= len(s2):
            windowHash = {}

            for i in range(left, right):
                if s2[i] not in windowHash:
                    windowHash[s2[i]] = 1
                else:
                    windowHash[s2[i]] += 1
            
            if windowHash == s1Hash:
                return True

            left += 1
            right += 1
        
        return False



        

