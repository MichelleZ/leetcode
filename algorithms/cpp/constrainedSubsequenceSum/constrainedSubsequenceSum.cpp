// Source: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> q;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i > k && q.front() == i - k - 1) {
                q.pop_front();
            }
            dp[i] = (q.empty() ? 0: max(dp[q.front()], 0)) + nums[i];
            while (!q.empty() && dp[i] >= dp[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            res = max(res, dp[i]);
        }
        return res;
    }
};
