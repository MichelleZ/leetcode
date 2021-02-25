// Source: https://leetcode.com/problems/task-scheduler/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        for (char t: tasks) counter[t]++;
        int maxcnt = 0;
        for (auto t: counter) {
            maxcnt = max(maxcnt, t.second);
        }
        int res = 0;
        res = (maxcnt - 1) * (n + 1);
        for (auto c: counter) {
            if (c.second == maxcnt) res++;
        }
        return max(res, (int)tasks.size());
    }
};
