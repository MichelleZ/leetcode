// Source: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res = INT_MAX;
        vector<pair<double, int>> workers(quality.size());
        for (int i = 0; i < quality.size(); i++) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        std::sort(workers.begin(), workers.end());
        priority_queue<int> heap;
        int sumq = 0;
        for (auto& w: workers) {
            if (heap.size() < K) {
                heap.push(w.second);
                sumq += w.second;
            }
            if (heap.size() == K) {
                res = min(res, w.first * sumq);
                sumq -= heap.top();
                heap.pop();
            }
        }
        return res;
    }
};
