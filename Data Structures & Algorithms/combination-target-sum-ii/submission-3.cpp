class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        rec(candidates, {}, target, 0, 0);
        return res;
    }

    void rec(vector<int>& candidates, vector<int> curr, int target, int currSum, int i) {
        if (currSum == target) {
            for (int i = 0; i < res.size(); i++) {
                sort(res[i].begin(), res[i].end());
                sort(curr.begin(), curr.end());

                if (res[i] == curr) {
                    return;
                }
            }
            res.push_back(curr);
        }
        if (i >= candidates.size() || currSum > target) {
            return;
        }

        rec(candidates, curr, target, currSum, i+1);
        curr.push_back(candidates[i]);
        rec(candidates, curr, target, currSum+candidates[i], i+1);
    }
};
