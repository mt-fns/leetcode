class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # map hash table of string to array of strings that are
        # in the same anagram class
        anagramHash = {}

        for string in strs:
            # a - z (index 0 - 26) store frequency of each letter
            stringArr = [0] * 26

            for char in string:
                charAscii = ord(char)
                stringArr[charAscii - ord('a')] += 1
            
            # convert frequency array into tuple so it can be used
            # as a key in the anagramHash
            stringTuple = tuple(stringArr)

            if stringTuple in anagramHash:
                anagramHash[stringTuple].append(string)
            else:
                anagramHash[stringTuple] = [string]

        return list(anagramHash.values())