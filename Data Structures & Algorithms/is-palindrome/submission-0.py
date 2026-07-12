class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleanedString = ""

        for char in s:
            if char.isalnum() and char != ' ':
                cleanedString += char
        
        cleanedString = cleanedString.lower()
        leftIndex = 0
        rightIndex = len(cleanedString) - 1

        while leftIndex <= rightIndex:
            if cleanedString[leftIndex] != cleanedString[rightIndex]:
                return False

            leftIndex += 1
            rightIndex -= 1

        return True


        