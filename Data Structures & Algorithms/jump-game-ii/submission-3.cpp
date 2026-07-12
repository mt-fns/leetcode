class Solution {
public:
    // get the minimum if we go with the maximum number per jump??
    // the first reachable range to get us there will be the one that is actually minimum

    int jump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return 0;
        }

        int jumps = 1;
        int currPosition = 0;

        // at every point, pick the max jump length from all positions that are reachable 
        while (currPosition < (nums.size()-1)) {
            int reachable = nums[currPosition] + currPosition;
            int maxReachable = 0;
            int nextPosition = currPosition;

            if (reachable >= (nums.size()-1)) {
                break;
            }

            for (int i = (currPosition+1); i <= reachable; i++) {
                if ((i+nums[i]) > maxReachable) {
                    maxReachable = i+nums[i];
                    nextPosition = i;
                }
            }

            cout << currPosition << endl;

            currPosition = nextPosition;
            jumps++;
        }

        return jumps;
    }
};
