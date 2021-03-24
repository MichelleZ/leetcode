// Source: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        // B = A + A prefix sum
        vector<int> p{0};
        for (int i = 0; i < 2; i++) {
            for (auto& a: A) {
                p.push_back(p.back() + a);
            }
        }

        int res = A[0];
        deque<int> q;
        q.push_back(0);
        for (int j = 1; j < p.size(); j++) {
            if (q.front() < j - n) {
                q.pop_front();
            }
            res = max(res, p[j] - p[q.front()]);
            while (!q.empty() && p[j] <= p[q.back()]) {
                q.pop_back();
            }
            q.push_back(j);
        }
        return res;
    }
};
