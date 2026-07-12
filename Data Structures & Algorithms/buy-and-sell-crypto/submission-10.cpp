class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // l,r = 0
        // check r+1, if r+1 < l, set l to r+1
        // check for profits
        int l = 0;
        int r = 0;
        int res = 0;

        while (r < prices.size()) {

            int curr = prices[r] - prices[l];
            if (curr > res) {
                res = curr;
            }

            if (prices[r] < prices[l]) {
                l = r;
            }

            r++;
        }

        return res;
    }
};
