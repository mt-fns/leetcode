class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left;
        vector<int> max_right(height.size(), 0);
        // fill[i] = max(0, min(max_left[i], max_right[i]) - height[i])
        vector<int> fill;

        int curr_max = 0;
        for (int i = 0; i < height.size(); i++) {
            max_left.push_back(curr_max);
            curr_max = max(curr_max, height[i]);
        }

        curr_max = 0;
        for (int i = height.size()-1; i >= 0; i--) {
            max_right[i] = curr_max;
            curr_max = max(curr_max, height[i]);
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += max(0, min(max_left[i], max_right[i]) - height[i]);
        }
        
        return res;
    }
};
