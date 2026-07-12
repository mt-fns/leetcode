class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # sliding window, scan for 'valid' windows and keep track
        # of the longest valid window length, a valid window is
        # a window where the window length - most frequent character within that window is < k
        # have an array that store the freq of all characters within a window and update this every window scan
        # if an invalid window is detected, move the left pointer right until the window is valid again
        freq = {}
        l = 0
        longestValidLength = 0

        # right pointer goes through all chars
        for r in range(len(s)):
            # increment freq of right pointer
            if s[r] not in freq:
                freq[s[r]] = 1
            else:
                freq[s[r]] += 1

            # while current window is invalid, move left pointer to the right until it becomes valid
            while (r - l + 1) - max(freq.values()) > k:
                freq[s[l]] -= 1
                l += 1
            
            longestValidLength = max(r - l + 1, longestValidLength)

        return longestValidLength