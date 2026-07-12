class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len_longest = 0;
        unordered_set<int> nums_set = {};
        unordered_set<int> used = {};

        for (int num : nums) {
            nums_set.insert(num);
        }

        for (int num : nums) {
            if (used.count(num)) {
                continue;
            }

            int curr_len = 1;
            int curr_num_inc = num + 1;
            int curr_num_dec = num - 1;

            while (nums_set.count(curr_num_dec)) {
                used.insert(curr_num_dec);
                curr_num_dec--;
                curr_len++;
            }

            while (nums_set.count(curr_num_inc)) {
                used.insert(curr_num_inc);
                curr_num_inc++;
                curr_len++;
            }

            if (curr_len > len_longest) {
                len_longest = curr_len;
            }
        }

        return len_longest;
    }
};
