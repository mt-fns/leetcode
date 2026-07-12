class Solution {
public:
    // rec(n) = rec(n-1) + rec(n-2)

    int climbStairs(int n) {
        vector<int> cache(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cache[0] = 1;
                continue;
            }
            if (i == 1) {
                cache[1] = 2;
                continue;
            }
            cache[i] = cache[i-1] + cache[i-2];
        }

        return cache[n-1];
    }
};
