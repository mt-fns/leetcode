class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;

        for (const auto & num : nums) {
            if (s.contains(num)) {
                return true;
            }
            s.insert(num);
        }

        return false;
    }
};