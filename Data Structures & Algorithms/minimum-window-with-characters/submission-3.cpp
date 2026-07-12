class Solution {
public:
    bool containsValidLetter(string t, vector<int> freq_list) {
        for (int i = 0; i < t.length(); i++) {
            if ((isupper(t[i]) && freq_list[t[i] - 'A' + 26]) || freq_list[t[i] - 'a']) {
                return true;
            }
        }

        return false;
    }

    bool containsAllValidLetters(vector<int> freq_list, vector<int> curr_freq_list) {
        for (int i = 0; i < freq_list.size(); i++) {
            if (freq_list[i] && (curr_freq_list[i] < freq_list[i])) {
                return false;
            }
        }

        return true;
    }

    bool isValidLetter(char x, vector<int> freq_list) {
        if ((isupper(x) && freq_list[x - 'A' + 26]) || freq_list[x - 'a']) {
            return true;
        }
        return false;
    } 

    string minWindow(string s, string t) {
        // keep track of what letters we've seen in the current window
        // move window if none of the letters in t is in our current window
        // or move window if all letters in t is in the current window -> move to the next nearest valid letter
        int l = 0;
        int r = 0;
        vector<int> freq_list(52, 0);
        vector <int> curr_freq_list(52, 0);

        string res = "";
        int res_len = 1000;

        // next valid character in the current window
        int next_valid_index = 0;
        // num of valid chars in current window
        int num_valid_chars = 0;


        for (int i = 0; i < t.length(); i++) {
            if (isupper(t[i])) {
                freq_list[t[i] - 'A' + 26]++;
            }
            else {
                freq_list[t[i] - 'a']++;
            }
        }

        while (r < s.length()) {
            if (isupper(s[r])) {
                curr_freq_list[s[r] - 'A' + 26]++;
            }
            else {
                curr_freq_list[s[r] - 'a']++;
            }

            std::cout << l << ", " << next_valid_index << std::endl;

            // keep track of the number of valid chars in current window
            // also keep track of the nearest valid char from the left pointer
            if (isValidLetter(s[r], freq_list)) {
                num_valid_chars++;
                if (num_valid_chars == 2) {
                    next_valid_index = r;
                }
            }     
            
            // if the current window contains no letters from t, move l and r
            if (!containsValidLetter(t, curr_freq_list)) {
                // reset curr freq list
                curr_freq_list.assign(52, 0);
                next_valid_index = 0;
                num_valid_chars = 0;

                l++;
                r++;
                continue;
            }

            // if the current window contains all of the char needed in freq list
            if (containsAllValidLetters(freq_list, curr_freq_list)) {
                if ((r - l + 1) < res_len) {
                    res_len = (r - l + 1);
                    res = s.substr(l, res_len);
                }

                // reset curr freq list, move window to next available letter
                if (next_valid_index != 0) {
                    r = next_valid_index;
                    l = next_valid_index;
                }

                curr_freq_list.assign(52, 0);
                next_valid_index = 0;
                num_valid_chars = 1;

                if (isupper(s[r])) {
                    curr_freq_list[s[r] - 'A' + 26]++;
                }
                else {
                    curr_freq_list[s[r] - 'a']++;
                }
            }

            r++;
        }

        return res;

    }
};
