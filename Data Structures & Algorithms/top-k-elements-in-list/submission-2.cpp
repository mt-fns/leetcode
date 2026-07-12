class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       // keep track of a frequency count of each element
       // then iterate through every unique element -> O(n)
       // if doing things this way -> O(n*k)

        // min or max heap
        // store k elements in this heap -> ideally top one being our kth most frequent
        // min heap of size k -> if new is greater and is added to the heap, we pop our least one
        // the top element is the kth most frequent

        // this is O(n*logn)

        // value, freq
        unordered_map<int, int> freq;

        // pq needs to store a pair (freq: val)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> res;

        for (const auto & num : nums) {
            freq[num]++;
        }

        for (const auto & [v, f] : freq) {
            min_heap.push({f, v});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        while (min_heap.size()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;
    }
};
