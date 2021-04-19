// Source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(begin(jobs), end(jobs));
        int res = 0;
        map<int, int> m{{0, 0}}; // {end time->maxprofit}
        for (const auto& job: jobs) {
            int p = prev(m.upper_bound(job[1]))->second + job[2];
            if (p > rbegin(m)->second) {
                m[job[0]] = p;
            }
        }
        return rbegin(m)->second;
    }
};
