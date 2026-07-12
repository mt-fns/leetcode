class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # find the min and max bananas in the pile, perform binary search within this range
        minRate = 1
        maxRate = max(piles)
        validMidRate = maxRate
        
        # perform binary search until we find a minimum midRate that satisfies time limit
        # keep decrementing valid midRate until it exceeds time limit to find the minimum valid midRate
        while minRate <= maxRate:
            midRate = int((minRate + maxRate) / 2)
            timeMidRate = 0

            # check the time required to finish all piles with current mid rate
            for i in piles:
                if midRate >= i:
                    timeMidRate += 1
                elif midRate < i:
                    timeToEat = i / midRate

                    # round up timeToEat if decimal
                    if round(timeToEat) < timeToEat:
                        timeToEat = round(timeToEat) + 1
                    else:
                        timeToEat = round(timeToEat)

                    timeMidRate += timeToEat
            
            # valid, keep decrementing mid rate until it becomes invalid
            if timeMidRate <= h:
                if midRate < validMidRate:
                    validMidRate = midRate
                maxRate = midRate - 1
            # too slow, move left pointer to a faster speed
            elif timeMidRate > h:
                minRate = midRate + 1
        
        return validMidRate


