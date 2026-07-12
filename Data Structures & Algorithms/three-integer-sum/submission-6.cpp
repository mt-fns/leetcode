class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // iterate throug the entire array
        // for every element, run 2 sum
        vector<vector<int>> res;
        unordered_map<int, int> num_set;
        unordered_set<string> used_indices = {};

        for (int i = 0; i < nums.size(); i++) {
            num_set[nums[i]] = i;
        }


        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) {
                    continue;
                }

                if (num_set.count(target - nums[j])) {
                    int k = num_set[target - nums[j]];
                    if (i == k || j == k) {
                        continue;
                    }

                    vector<int> curr_indices = {nums[i], nums[j], nums[k]};
                    sort(curr_indices.begin(), curr_indices.end());
                    string str_key = to_string(curr_indices[0]) + "," + to_string(curr_indices[1]) + "," + to_string(curr_indices[2]);
                    if (used_indices.count(str_key)) {
                        continue;
                    }

                    used_indices.insert(str_key);
                    res.push_back({nums[i],nums[j],target - nums[j]});
                }
            }
        }

        return res;
    }
};
