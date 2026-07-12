class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # use 2 pointers, if duplicate move left pointer to the right until no more duplicates
        # keep hash set of all letters in the current substring to keep track of duplicates
        # remove duplicates from hash set with left pointer moving to the right
        # keep track of the longest length of the string
        substringLetters = set()
        length = 0
        left = 0

        for r in range(len(s)):
            while s[r] in substringLetters:
                substringLetters.remove(s[left])
                left += 1
            
            substringLetters.add(s[r])
            length = max(r - left + 1, length)
        
        return length
            

        
        