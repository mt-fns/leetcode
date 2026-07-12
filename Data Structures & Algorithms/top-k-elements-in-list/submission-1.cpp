class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // keep track of freq map
        // iterate through all elements to find the kth smallest
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i])) {
                freq[nums[i]]++;
            }
            else {
                freq[nums[i]] = 1;
            }
        }

        vector<pair<int, int>> sorted;
        vector<int> res;

        for (auto p : freq) {
            sorted.push_back({p.second, p.first});
        }

        sort(sorted.rbegin(), sorted.rend());

        for (int i = 0; i < k; i++) {
            res.push_back(sorted[i].second);
        }

        return res;
    }
};
