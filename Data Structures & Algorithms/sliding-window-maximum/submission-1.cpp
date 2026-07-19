class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 1 <= nums.length <= 100,000
        // -10,000 <= nums[i] <= 10,000
        // 1 <= k <= nums.length
        // O(k*n)
        
        // [1,2,1,0,1,2,6]
        // heap + set
        // max 1 -> 2 (1,2,1)
        // max 2 -> 2 (2,1,0)

        // add new element to max heap and then set in each window
        // if window -> this is nlogn since the there can only ever be
        // n elements in the heap and each insert/pop is log(n)

        vector<int> res;
        unordered_map<int,int> curr_window;
        priority_queue<int> max_window;
        int l = 0;
        int r = k-1;

        for (int i = 0; i < k; i++) {
            curr_window[nums[i]]++;
            max_window.push(nums[i]);
        }

        while (r < nums.size()) {
            int curr_max = max_window.top();

            while (!curr_window[curr_max]) {
                max_window.pop();
                curr_max = max_window.top();

                // cout << curr_max << endl;
            }

            res.push_back(curr_max);
            curr_window[nums[l]]--;
            l++;
            r++;

            if (r >= nums.size()) {
                break;
            }

            curr_window[nums[r]]++;
            max_window.push(nums[r]);
        }

        return res;
    }
};
