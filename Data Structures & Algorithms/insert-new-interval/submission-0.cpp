class Solution {
public:
    bool is_overlapping(vector<int> &interval1, vector<int> &interval2) {
        if (((interval1[0] >= interval2[0]) && (interval1[0] <= interval2[1]))
        || ((interval1[1] >= interval2[0]) && (interval1[1] <= interval2[1]))
        || ((interval1[0] <= interval2[0]) && (interval1[1] >= interval2[1]))
        || ((interval2[0] <= interval1[0]) && (interval2[1] >= interval1[1]))) {
            return true;
        }

        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> curr_new = newInterval;

        for (auto & interval : intervals) {
            if (is_overlapping(curr_new, interval)) {
                curr_new[0] = min(curr_new[0], interval[0]);
                curr_new[1] = max(curr_new[1], interval[1]);
                continue;
            }
            res.push_back(interval);
        }

        res.push_back(curr_new);
        sort(res.begin(), res.end());
        return res;
    }
};
