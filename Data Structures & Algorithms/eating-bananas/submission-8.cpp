class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *max_element(begin(piles), end(piles));
        int res = numeric_limits<int32_t>::max();

        while (l <= r) {
            int mid = (l+r)/2;
            int time = 0;

            cout << mid << endl;
            for (const auto & p : piles) {
                time += (p + mid - 1) / mid;
            }

            if (time <= h) {
                cout << time << endl;
                res = min(res, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
    }
};
