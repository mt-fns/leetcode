class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // start with 2 pointers at index 0
        // calculate profit
        // move r, if prices[r] < prices[l] move l to r
        // [10,1,5,6,7,1]
        // l = 0, r = 0
        // l = 0, r = 1 -> profit = -9, move l = r
        // l = 1, r = 2, -> profit = 4
        // l = 1, r = 3, -> profit = 5
        // ... = profit = 6
        // return 6

        int res = -1;
        int l = 0;
        int r = 0;

        while (l < prices.size() && r < prices.size()) {
            int profit = prices[r] - prices[l];
            res = max(res, profit);

            if (prices[l] > prices[r]) {
                l = r;
            }
            r++;
        }

        return max(res, 0);
    }
};
