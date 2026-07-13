class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;

        for (int i = 31; i >= 0; i--) {
            reversed |= (((n & (1U << (31-i))) >> (31-i)) << i);
        }

        return reversed;
    }
};
