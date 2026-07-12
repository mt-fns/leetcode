class Solution {
public:
    int search(vector<int>& nums, int target) {
        // do binary search to find the left/right half
        // check whether the smallest element (l) > target -> search right 
        // check whether largest element(r) < target -> search left
        // if m > l and m < r we are in left
        // if already sorted do normal binary search
        int l = 0;
        int r = nums.size() - 1;
        

        // check if we're on left sorted or right sorted 
        // if we're in left and target < l, search right
        // if we're in right and mid <= target <= right, search right

        // if we're in right and target > right, search left
        // if we're in left and l <= target <= mid, search left



        while (l <= r) {
            int m = (l+r)/2;
            cout << l << ' ' << r << ' ' << m << endl;

            // already in sorted portion
            if (nums[l] <= nums[r]) {
                if (nums[m] == target) {
                    return m;
                }
                else if (nums[m] > target) {
                    r = m-1;
                }
                else {
                    l = m+1;
                }
                continue;
            }

            if (nums[m] == target) {
                return m;            
            }
            
            // in left
            if (nums[l] <= nums[m] && nums[m] >= nums[r]) {
                if (nums[l] <= target && target <= nums[m]) {
                    cout << "test" << endl;
                    r = m-1;
                }
                else {
                    cout << "test1" << endl;
                    l = m+1;
                }
            }
            else {
                if (nums[m] <= target && target <= nums[r]) {
                    cout << "test2" << endl;
                    l = m+1;
                }
                else {
                    cout << "test3" << endl;
                    r = m-1;
                }
            }
        }


        return -1;
    }
};
