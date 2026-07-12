class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False

        letterT = {}
        letterS = {}

        for i in range(len(s)):
            if s[i] in letterS:
                letterS[s[i]] = 1 + letterS[s[i]]
            else:
                letterS[s[i]] = 1
            
            if t[i] in letterT:
                letterT[t[i]] = 1 + letterT[t[i]]
            else:
                letterT[t[i]] = 1
        
        return letterT == letterS

        