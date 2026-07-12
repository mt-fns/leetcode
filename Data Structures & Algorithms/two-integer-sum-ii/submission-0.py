class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        output = []

        while left < right:
            if left == right:
                break
            
            if numbers[right] + numbers[left] > target:
                right -= 1
            elif numbers[right] + numbers[left] < target:
                left += 1
            else:
                output.append(left + 1)
                output.append(right + 1)
                break
        
        return output
            

        