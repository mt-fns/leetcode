class Solution {
public:
    bool isValid(string s) {
        stack<char> parantheses;

        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') {
                parantheses.push(c);
            }
            else {
                if ((c == ']' || c == '}' || c == ')') && parantheses.empty()) {
                    return false;
                }

                if (c == ']' && parantheses.top() == '[') {
                    parantheses.pop();
                }
                else if (c == '}' && parantheses.top() == '{') {
                    parantheses.pop();
                }
                else if (c == ')' && parantheses.top() == '(') {
                    parantheses.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (!parantheses.empty()) {
            return false;
        }

        return true;
    }
};
