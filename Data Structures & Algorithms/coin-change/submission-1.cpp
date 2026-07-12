class Solution {
public:
    // let dp(i) be the minimum number of coins with amount i
    // res = inf
    // for all coins:
    // res = min(1+dp(i-coin))
    // if i == 0: return 1
    // if i < 0: return 0

    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount + 1, -2);

        int res = dp(amount, coins, cache);
        return res;
    }

    int dp(int amount, vector<int>& coins, vector<int>& cache) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }

        if (cache[amount] != -2) {
            return cache[amount];
        }

        int res = -1;
        for (int i = 0; i < coins.size(); i++) {
            int curr = dp(amount-coins[i], coins, cache);
            if (curr == -1) {
                continue;
            }

            if (res == -1) {
                res = curr+1;
                continue;
            }
            res = min(res, curr+1);
        }

        cache[amount] = res;
        return res;
    }
};
