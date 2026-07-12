class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);

        if ((sumGas - sumCost) < 0) {
            return -1;
        }

        vector<int> diff;

        for (int i = 0; i < cost.size(); i++) {
            diff.push_back(gas[i] - cost[i]);
        }

        for (int i = 0; i < diff.size(); i++) {
            int currDiff = diff[i];

            if (currDiff < 0) {
                continue;
            }

            for (int j = i+1; j < diff.size(); j++) {
                cout << i << endl;
                currDiff += diff[j];

                if (currDiff < 0) {
                    break;
                }

                if (j == (diff.size()-1)) {
                    return i;
                } 
            }

            if (i == (diff.size()-1)) {
                cout << "TEST" << endl;
                return i;
            }
        }

        return -1;
    }
};
