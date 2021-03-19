// Source: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i - 1] + A[i - 1];
        }
        int res = n + 1;
        deque<int> q;
        for (int i = 0; i < sums.size(); i++) {
            while (!q.empty() && sums[i] <= sums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && sums[i] - sums[q.front()] >= K) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};
