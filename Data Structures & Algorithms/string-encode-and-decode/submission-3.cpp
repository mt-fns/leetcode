class Solution {
public:

    // 4/neet4/code4/love3/you
    // 10/abcdefghkl4/code
    string encode(vector<string>& strs) {
        string res = "";
        for (string str : strs) {
            string encoded = "";
            encoded += to_string(str.length()) + "/" + str;
            res += encoded;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res = {};

        int i = 0;

        std::cout << s << std::endl;


        while (i < s.length()) {
            // doesn't work for multiple digits - have to check with delimiter instead
            int j = i;

            while (s[j] != '/') {
                j++;
            }

            int record_len = j - i;

            int length = stoi(s.substr(i, record_len));
            std::cout << length << std::endl;
            res.push_back(s.substr(i+record_len+1, length));

            length += record_len + 1;
            i += length;
        }

        return res;
    }
};
