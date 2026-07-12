class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep track of current set
        // l,r = 0
        // if there is a dupiclate move left by one
        // else keep moving r

        int l = 0;
        int r = 0;
        int res = 0;

        unordered_set<char> seen;

        while (r < s.length()) {
            if (seen.count(s[r])) {
                // keep moving l until we've no dupiclate s[r]
                while (s[l] != s[r]) {
                    seen.erase(s[l]);
                    l++;
                }
                seen.erase(s[l]);                    
                l++;
            }
            seen.insert(s[r]);

            int curr = r - l + 1; 

            if (curr > res) {
                res = curr;
            }
            r++;
        }

        return res;
    }
};
