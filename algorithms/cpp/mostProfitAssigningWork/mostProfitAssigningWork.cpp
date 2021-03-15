// Source: https://leetcode.com/problems/most-profit-assigning-work/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());
        int res = 0;
        int i = 0;
        int best = 0;
        for (int w: worker) {
            while (i < n && w >= jobs[i].first) {
                best = max(best, jobs[i++].second);
            }
            res += best;
        }
        return res;
    }
};
