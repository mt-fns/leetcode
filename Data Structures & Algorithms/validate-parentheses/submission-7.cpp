class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;
        unordered_map<char, char> pairs = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

        for (const auto & c : s) {
            if (c == '{' || c == '(' || c == '[') {
                seen.push(c);
                continue;
            }

            if (seen.size() == 0) {
                return false;
            }

            char top = seen.top();
            seen.pop();
            if (pairs[top] == c) {
                continue;
            }

            return false;
        }

        return seen.size() == 0;
    }
};
