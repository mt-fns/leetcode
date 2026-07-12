class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = []
        

    def push(self, val: int) -> None:
        self.stack.append(val)

        currMinIndex = len(self.minStack) - 1

        if currMinIndex < 0:
            self.minStack.append(val)
            return

        if val < self.minStack[currMinIndex]:
            self.minStack.append(val)
        else:
            self.minStack.append(self.minStack[currMinIndex])
        

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        
    def getMin(self) -> int:
        return self.minStack[-1]
        
