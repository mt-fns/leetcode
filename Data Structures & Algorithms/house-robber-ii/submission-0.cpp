class Solution {
public:
    // 2 dps: 1 where we pick the first house and exclude the last
    // another we we pick the last and exclude the first
    // pick the max of these 2
    // let dp[i] be the max val for robbing house 0..i
    int rob(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        dp2[0] = 0;
        dp2[1] = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            if (i == (nums.size() - 1)) {
                dp1[i] = dp1[i-1];
                break;
            }

            dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]);
        }

        for (int i = 2; i < nums.size(); i++) {
            dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
        }

        return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
    }
};
