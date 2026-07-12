class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        rec(nums, curr, target, 0, 0);
        return res;
    }

    void rec(vector<int> & nums, vector<int> curr, int target, int i, int currSum) {
        if (currSum == target) {
            res.push_back(curr);
            return;
        }

        if (i >= nums.size() || currSum > target) {
            return;
        }

        rec(nums, curr, target, i+1, currSum);
        curr.push_back(nums[i]);
        rec(nums, curr, target, i, currSum+nums[i]);
    }
};
