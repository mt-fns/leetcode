class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map -> set: vector<string>
        map<vector<int>, vector<string>> store;
        vector<vector<string>> res;

        for (const auto & str : strs) {
            vector<int> curr_store(26, 0);
            for (const auto & c : str) {
                curr_store[c - 'a']++;
            }
            store[curr_store].push_back(str);
        }

        for (const auto & [key, value] : store) {
            res.push_back(value);
        }

        return res;
    }
};
