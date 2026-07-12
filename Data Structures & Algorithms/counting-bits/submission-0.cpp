class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for (int i = 0; i <= n; i++) {
            int mask = 1;
            int count = 0;

            for (int j = 0; j < 32; j++) {
                if (mask & i) {
                    count++;
                }
                mask = mask << 1;
            }

            res.push_back(count);
        }

        return res;
    }   
};
