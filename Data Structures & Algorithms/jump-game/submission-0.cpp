class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;

        // check that i is reachable
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxPos) {
                maxPos = max(maxPos, i+nums[i]);
            }
        }

        if (maxPos >= (nums.size()-1)) {
            return true;
        }
        return false;   
    }
};
