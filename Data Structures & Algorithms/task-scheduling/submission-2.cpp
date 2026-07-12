class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // tasks can be completed in any order
        // pick the task that has the most duplicates -> less idle time
        // if that task is on cool down, pick the second most frequent
        // checking which task has the most is O(1) -> use a freq list
        // keep track of another list that is the last tick that a task was completed
        // if no task has can run, idle and increment

        int tick = 0;
        vector<int> freq(26, 0);
        vector<int> last(26, -1);
        int numTasks = tasks.size();

        for (const auto & task : tasks) {
            freq[task - 'A']++;
        }


        while (numTasks) {
            int currTask = -1;
            int freqCurr = 0;

            for (int i = 0; i < freq.size(); i++) {
                if (freq[i] > freqCurr) {
                    if ((last[i] == -1) || (n < (tick - last[i]))) {
                        currTask = i;
                        freqCurr = freq[i];
                    }
                }
            }

            if (currTask < 0) {
                tick++;
                cout << "idle" << endl;

                continue;
            }

            cout << currTask << endl;
            freq[currTask]--;
            last[currTask] = tick;
            numTasks--;

            tick++;
        }

        return tick;
    }
};
