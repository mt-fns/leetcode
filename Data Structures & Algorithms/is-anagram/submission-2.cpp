class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s1;
        map<char, int> s2;

        for (const auto & c : s) {
            s1[c]++;
        }

        for (const auto & c : t) {
            s2[c]++;
        }

        return s1 == s2;
    }
};
