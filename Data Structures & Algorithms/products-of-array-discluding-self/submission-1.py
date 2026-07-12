class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products = []
        product = 1
        current = 0
        zeroCount = 0

        while current < len(nums):
            if current == 0:
                for i in range(len(nums)):
                    if i == current:
                        continue
                    if nums[i] == 0:
                        zeroCount += 1
                    else:
                        product = product * nums[i]
                
                if zeroCount > 0:
                    products.append(0)
                    product = product * nums[0]

                else:
                    products.append(product)

            elif zeroCount == 1:
                if nums[current] == 0:
                    products.append(product)
                else:
                    products.append(0)

            elif zeroCount > 1:
                products.append(0)

            else:
                product = product * nums[current - 1] / nums[current]
                products.append(int(product))

            current += 1
            
        return products

        