class Solution {
public:
    int findMin(vector<int> &nums) {
        // check middle
        // if m > l and m > r, we are in the left, search in m+1 (search right)
        // else we are in the right search in m-1 (search left)
        int l = 0;
        int r = nums.size() - 1;
        int res = 10000;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
            }

            int m = (l + r)/2;
            res = min(res, nums[m]);
            if (nums[m] >= nums[l] && nums[m] >= nums[r]) {
                l = m+1;
            }
            else {
                r = m-1;
            }
            cout << m << endl;

        }
        return res;
    }
};
