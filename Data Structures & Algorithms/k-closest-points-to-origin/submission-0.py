class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        coordList = []
        index = 0

        for coord in points:
            x, y = coord[0], coord[1]
            dist = math.sqrt((x - 0)**2 + (y - 0)**2)
            coordList.append((dist, index))
            index += 1
        
        kClosest = []
        heapq.heapify(coordList)
        kCounter = 0

        while heapq and kCounter < k:
            pointsIndex = heapq.heappop(coordList)[1]
            kClosest.append(points[pointsIndex])
            kCounter += 1
        
        return kClosest
        