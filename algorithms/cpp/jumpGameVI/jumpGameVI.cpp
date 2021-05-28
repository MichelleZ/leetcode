// Source: https://leetcode.com/problems/jump-game-vi/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> q{{0}};
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i] + dp[q.front()];
            while (!q.empty() && dp[i] > dp[q.back()])
                q.pop_back();
            while (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            q.push_back(i);
        }
        return dp[n - 1];
    }
};
