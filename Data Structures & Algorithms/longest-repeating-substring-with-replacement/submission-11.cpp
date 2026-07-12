class Solution {
public:
    int characterReplacement(string s, int k) {
        // wort case O(n^2)
        // maintain a window keeping track of the most frequent element
        // as long as window.size - missing_char > k, window is valid
        // if window is invalid, move leftmost pointer to r until its valid
        // how do we update missing char?
        // "AAABABB" -> 
        // keep track of a freq list for all chars in curr window?
        // find max freq in current window

        vector<int> freq(26, 0);
        int l = 0;
        int r = 0;
        int currMax = 0;
        int res = 0;

        while (l < s.length() && r < s.length()) {
            freq[s[r] - 'A']++;

            currMax = max(currMax, freq[s[r] - 'A']);
            int windowLen = r-l+1;

            if ((windowLen-currMax) > k) {
                cout << "here" << endl;
                freq[s[l] - 'A']--;
                l++;

                int newCurr = -1;
                for (const auto & i : freq) {
                    if (i > newCurr) {
                        newCurr = i;
                    }
                }

                cout << currMax << endl;
                currMax = newCurr;
            }
            
            windowLen = r-l+1;
            if ((windowLen-currMax) <= k) {
                cout << "here 2 " <<  windowLen << " " << currMax << endl;
                res = max(res, windowLen);
            }

            r++;
        }
        
        return res;
        
    }
};
