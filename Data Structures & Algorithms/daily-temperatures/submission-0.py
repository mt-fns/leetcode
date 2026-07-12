class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # maintain a stack consisting of temp and item, go through the array
        # and add to stack if it is empty or if the element before it is >
        # if current element greater than the element before it, pop from stack and keep track of count 
        # until prev element is >= current element, add this element to stack
        res = [0] * len(temperatures)
        stack = []

        for i in range(len(temperatures)):
            while len(stack) > 0 and stack[-1][0] < temperatures[i]:
                prev = stack.pop()
                res[prev[1]] = i - prev[1]
            stack.append([temperatures[i], i])
        
        return res



        