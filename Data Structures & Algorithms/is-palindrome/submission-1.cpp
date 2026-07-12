class Solution {
public:
    bool isPalindrome(string s) {
        string parsed = "";

        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                parsed += tolower(s[i]);
            }
        }

        cout << parsed << endl;

        int l = 0;
        int r = parsed.length() - 1;

        while (l < r) {
            if (parsed[l] != parsed[r]) {
                std::cout << parsed[l] << std::endl;
                std::cout << parsed[r] << std::endl;
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
