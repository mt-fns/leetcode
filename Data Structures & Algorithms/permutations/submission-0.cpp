class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, {});
        return res;
    }

    void dfs(vector<int> remaining, vector<int> curr) {
        if (remaining.size() == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < remaining.size(); i++) {
            vector<int> copy = remaining;
            vector<int> temp = curr;

            temp.push_back(remaining[i]);
            copy.erase(copy.begin() + i);
            dfs(copy, temp);
        }
    }
 };
