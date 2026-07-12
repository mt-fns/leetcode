class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        timeToTarget = []
        stack = []

        for i in range(len(position)):
            calculatedTime = (target - position[i]) / speed[i]
            timeToTarget.append((position[i], calculatedTime))

        timeToTarget.sort()

        for i in timeToTarget:
            # same car fleet
            while len(stack) > 0 and stack[-1][0] <= i[0] and stack[-1][1] <= i[1]:
                stack.pop()
            
            stack.append(i)

        return len(stack)


        