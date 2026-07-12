class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<vector<int>> res;
       vector<int> curr; 

        dfs(target, nums, 0, res, curr);

        return res;
    }

    void dfs(int target, vector<int> nums, int i, vector<vector<int>> &res, vector<int> &curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || i >= nums.size()) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(target - nums[i], nums, i, res, curr);

        curr.pop_back();
        dfs(target, nums, i+1, res, curr);
    }
};
