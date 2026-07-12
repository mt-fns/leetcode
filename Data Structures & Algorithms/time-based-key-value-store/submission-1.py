class TimeMap:

    def __init__(self):
        # {key: [[timestamp, value], [timestamp, value]]}
        self.keys = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.keys:
            self.keys[key] = [[timestamp, value]] 
        else:
            self.keys[key].append([timestamp, value])
        
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.keys:
            return ""
        else:
            # [[timestamp, value], [timestamp, value]]
            keyArray = self.keys[key]
            left = 0
            right = len(keyArray) - 1

            while left <= right:
                mid = (left + right) // 2
                if keyArray[mid][0] < timestamp:
                    left = mid + 1
                elif keyArray[mid][0] > timestamp:
                    right = mid - 1
                else:
                    return keyArray[mid][1]
            
            # value at time stamp not found, return last time stamp
            # if last time stamp if after requested time stamp, return empty string
            if keyArray[left - 1][0] > timestamp:
                return ""

            return keyArray[left - 1][1]
        
