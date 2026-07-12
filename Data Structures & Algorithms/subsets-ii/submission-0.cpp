class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        rec(nums, {}, 0);

        return res;
    }

    void rec(vector<int>& nums, vector<int> curr, int i) {
        if (i >= nums.size()) {
            for (int i = 0; i < res.size(); i++) {
                sort(res[i].begin(), res[i].end());
                sort(curr.begin(), curr.end());

                if (curr == res[i]) {
                    return;
                }
            }

            res.push_back(curr);
            return;
        }

        rec(nums, curr, i+1);
        curr.push_back(nums[i]);
        rec(nums, curr, i+1);
    }
};
