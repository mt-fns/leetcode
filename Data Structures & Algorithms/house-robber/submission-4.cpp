class Solution {
public:
    // for each house: we can either select or deselect
    // if selected, then we must not select the house after it
    // if unselected, we are allowed to select the house after it
    // find the max between selecting vs unselecting the house
    // dp(i) = max(nums[i] + dp(i+2), dp(i+1))

    int rob(vector<int>& nums) {
        // cache[i] max of res from house 1..i if i were selected
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> cache(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                cache[i] = nums[i];
                continue;
            }
            if (i == 1) {
                cache[i] = max(nums[1], nums[0]);
                continue;
            }

            cache[i] = max(cache[i-1], cache[i-2] + nums[i]);
        }


        return cache[nums.size() - 1];
    }
};
