class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_ones = 0;
        uint32_t mask = 1;

        for (int i = 0; i < 32; i++) {
            if (n & mask) {
                num_ones++;
            }

            mask = mask << 1;
        }

        return num_ones;
    }
};
