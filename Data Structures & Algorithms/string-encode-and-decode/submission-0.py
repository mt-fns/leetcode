class Solution:

    def encode(self, strs: List[str]) -> str:
        ret = ""

        for string in strs:
            stringLen = len(string)
            ret += f"{str(stringLen)}#{string}"
        
        return ret


    def decode(self, s: str) -> List[str]:
        currIndex = 0
        ret = []

        while currIndex < len(s):
            stringLen = ""

            for char in s[currIndex:]:
                currIndex += 1
                if char == "#":
                    break
                stringLen += char
            
            stringLen = int(stringLen)
            currString = ""

            for i in range(stringLen):
                if currIndex + i >= len(s):
                    break
                
                currString += s[currIndex + i] 

            currIndex += stringLen
            ret.append(currString)

        return ret

