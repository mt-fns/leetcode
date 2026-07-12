class Solution {
public:

    int numDecodings(string s) {
        if (s.size() == 0) {
            return 1;
        }

        return dp(0, s);
    }

    int dp(int i, string& s) {
        if (i >= (s.size())) {
            return 1;
        }

        if (s[i] == '1') {
            if (i < (s.size() - 1)) {
                return dp(i+1, s) + dp(i+2, s);
            }
        }

        if (s[i] == '2') {
            if (i < (s.size() - 1) && s[i+1] <= '6') {
                return dp(i+1, s) + dp(i+2, s);
            }
        }

        if (s[i] != '0') {
            return dp(i+1, s);
        }

        return 0;
    }
};
