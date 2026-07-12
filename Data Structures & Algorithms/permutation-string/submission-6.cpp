class Solution {
public:
    bool checkWindow(map<char, int>& window_freq) {
        for (const auto & pair : window_freq) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = 0;

        map<char, int> freq;
        map<char, int> window_freq;
        set<char> letters;

        for (const auto & c : s1) {
            if (freq.count(c)) {
                freq[c]++;
            }
            else {
                freq[c] = 1;
            }
            letters.insert(c);
        }

        window_freq = freq;

        // reset window, later
        // move left until valid
        // keep moving right each iter
        // if r invalid, reset window, increment r, move l to r
        while (r < s2.size()) {
            if (letters.count(s2[r])) {
                window_freq[s2[r]]--;
                while (window_freq[s2[r]] < 0) {
                    window_freq[s2[l]]++;
                    l++;
                }
                
                if (checkWindow(window_freq)) {
                    return true;
                }
            }
            else {
                window_freq = freq;
                l = r;
            }
            r++;
        }


        return false;
    }
};
