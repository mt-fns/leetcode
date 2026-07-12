class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # keep track of 2 pointers at the start of the array
        # move one of the pointers out until a repeating character has been found
        # keep track of all characters we've seen in a set
        # keep track of the count of the current number of characters between the 2 pointers

        l, r = 0, 0
        seen = set()
        longestCount = 0

        while r < len(s):
            if s[r] in seen:
                currentLength = r - l
                if currentLength > longestCount:
                    longestCount = currentLength
                
                while s[r] in seen:
                    seen.remove(s[l])
                    l += 1
            
            seen.add(s[r])
            r += 1
        
        if (r - l) > longestCount:
            longestCount = r - l

        return longestCount
            

                
        