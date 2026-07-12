class Solution:
    def isValid(self, s: str) -> bool:
        # O(n) time O(n) space solution
        stack = []
        bracesMap = {"[": "]", "{": "}", "(": ")"}

        for char in s:
            if char == "(" or char == "{" or char == "[":
                stack.append(char)
            else:
                if len(stack) < 1:
                    return False

                openingBracket = stack.pop()
                if char != bracesMap[openingBracket]:
                    return False
        
        if len(stack) > 0:
            return False
        
        return True
