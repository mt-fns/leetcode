class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum = nums[0];
        int l = 0;
        int r = 0;
        int best_window = numeric_limits<int>::max();

        while (l < nums.size() && r < nums.size()) {
            if (curr_sum < target) {
                r++;
                if (r >= nums.size()) {
                    break;
                }
                curr_sum += nums[r];
            } else {
                int window_size = (r-l+1);
                best_window = min(window_size, best_window);
                curr_sum -= nums[l];
                l++;
            }
        }

        if (best_window == numeric_limits<int>::max()) {
            return 0;
        }

        return best_window;
    }
};