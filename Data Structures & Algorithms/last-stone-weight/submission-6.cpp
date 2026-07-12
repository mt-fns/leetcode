class Solution {
public:
    // keep track of the 2 heaviest ones
    // mash them, see what weight returns
    // add remaining weight back and pick biggest one
    // if one remains, it is the last one
    priority_queue<int> max_heap;

    int lastStoneWeight(vector<int>& stones) {
        for (int w : stones) {
            max_heap.push(w);
        }

        while (!max_heap.empty()) {
            int i = max_heap.top();
            max_heap.pop();

            if (max_heap.empty()) {
                return i;
            }

            int j = max_heap.top();
            max_heap.pop();
            max_heap.push(i-j);
        }

        return 0;
    }
};
