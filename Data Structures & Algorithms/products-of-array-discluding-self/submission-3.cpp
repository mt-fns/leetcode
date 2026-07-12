class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                continue;
            }
            prefix[i] = prefix[i-1] * nums[i-1];

        }

        for (int i = (nums.size() - 1); i >= 0; i--) {
            if (i == (nums.size() - 1)) {
                continue;
            }
            suffix[i] = suffix[i+1] * nums[i+1];
            std::cout << suffix[i] << std::endl;

        }

        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
