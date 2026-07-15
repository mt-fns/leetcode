class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        bool should_carry = false;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 && j >= 0) {
            char curr_digit = '0';
            bool next_should_carry = false;

            if (a[i] != b[j]) {
                curr_digit = '1';
            } else if (a[i] == '1' && b[j] == '1') {
                next_should_carry = true;
            }

            if (should_carry) {
                if (curr_digit == '1') {
                    next_should_carry = true;
                    curr_digit = '0';
                } else {
                    curr_digit = '1';
                }
            }

            res += curr_digit;
            should_carry = next_should_carry;
            i--;
            j--;
        }

        while (i >= 0) {
            char curr_digit = a[i];

            if (should_carry) {
                if (curr_digit == '1') {
                    curr_digit = '0';
                } else {
                    should_carry = false;
                    curr_digit = '1';
                }
            }

            res += curr_digit;
            i--;
        }

        while (j >= 0) {
            char curr_digit = b[j];

            if (should_carry) {
                if (curr_digit == '1') {
                    curr_digit = '0';
                } else {
                    should_carry = false;
                    curr_digit = '1';
                }
            }

            res += curr_digit;
            j--;
        }

        if (should_carry) {
            res += '1';
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};