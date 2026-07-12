class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // store k/v pairs of letters that appear in a word 
        // and the number of times they appear
        // check if new hash map is the same as any other ones
        // O(mn) time -> potentially n unique words and at most m letters in a word
        // O(n) space -> n unique words and at most 26 letters in the alphabet
        unordered_map<string, vector<string>> res;

        for (const auto& str : strs) {
            // freq list
            vector<int> freqs(26, 0);

            for (char c : str) {
                freqs[c - 'a']++;
            }

            // turn freq list into string for hash key
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(freqs[i]) + ',';
            }

            res[key].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};
