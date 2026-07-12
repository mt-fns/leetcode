class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int longest = 0;
        int x = -1;
        int y = -1;

        for (int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r-l)+1 > longest) {
                    longest = (r-l)+1;
                    x = l;
                    y = r;
                }

                l--;
                r++;
            }

            l = i;
            r = i+1;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r-l)+1 > longest) {
                    longest = (r-l)+1;
                    x = l;
                    y = r;
                }

                l--;
                r++;
            }
        }

        return s.substr(x, longest);

    }
};
