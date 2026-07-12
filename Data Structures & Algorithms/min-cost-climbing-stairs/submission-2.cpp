class Solution {
public:
    // let dp[i] be the min cost to reach the top from floor i... when floor i is chosen

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2, 0);

        for (int i = (cost.size()-1); i >= 0; i--) {
            dp[i] = min(cost[i] + dp[i+1], cost[i] + dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};
