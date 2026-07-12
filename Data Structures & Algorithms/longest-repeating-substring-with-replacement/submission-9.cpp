class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window
        // keep track of frequency list
        // change to element with most frequent
        // if we run out of k, move left until we restore k
        // repeat the previous step (move right + change element with most freq)
        int l = 0;
        int r = 0;
        
        int freq = 0;
        vector<int> freq_list(26, 0);

        int res = 0;

        // check for most frequent element in window
        for (int r = 0; r < s.length(); r++) {
            // Expand: add s[r] to window
            freq_list[s[r] - 'A']++;
            freq = max(freq, freq_list[s[r] - 'A']);
            
            int curr_len = r - l + 1;
            
            // Check if current window is valid
            if (curr_len - freq <= k) {
                // Valid window, update result
                res = max(res, curr_len);
            } 
            else {
                // Invalid window, must shrink
                freq_list[s[l] - 'A']--;
                l++;
                
                // Recalculate freq after shrinking
                freq = 0;
                for (int f : freq_list) {
                    freq = max(freq, f);
                }
            }
        }
        
        return res;
    }
};
