class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>> heap;

        for (int i = 0; i < points.size(); i++) {
            int dist =  points[i][0] * points[i][0] + points[i][1] * points[i][1];
            heap.push({dist, points[i]});

            if (heap.size() > k) {
                heap.pop();
            }
        }


        for (int i = 0; i < k; i++) {
            pair<int, vector<int>> d = heap.top();
            heap.pop();
            res.push_back(d.second);
        }

        return res;
    }
};
