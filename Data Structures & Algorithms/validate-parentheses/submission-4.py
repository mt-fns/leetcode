class Solution:
    def isValid(self, s: str) -> bool:
        # O(n) time O(n) space solution
        stack = []
        bracesMap = {"[": "]", "{": "}", "(": ")"}

        for char in s:
            if char == "(" or char == "{" or char == "[":
                stack.append(char)
            else:
                # check that there exists an opening bracket corresponding to the closing bracket
                if len(stack) < 1:
                    return False

                openingBracket = stack.pop()

                # check that the opening bracket on the stack corresponds to the closing bracket correctly
                if char != bracesMap[openingBracket]:
                    return False
        
        # check that there are no more opening brackets left
        if len(stack) > 0:
            return False
        
        return True
