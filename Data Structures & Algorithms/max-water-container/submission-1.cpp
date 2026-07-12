class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int curr = (r-l)*min(heights[l],heights[r]);
            if (curr > res) {
                res = curr;
            }

            if (heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return res;
    }
};
