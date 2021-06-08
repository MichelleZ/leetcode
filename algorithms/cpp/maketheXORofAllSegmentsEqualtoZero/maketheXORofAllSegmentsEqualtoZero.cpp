// Source: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> groupcnt(k);
        vector<unordered_map<int, int>> group(k);
        for (int i = 0; i < n; i++) {
            groupcnt[i % k]++;
            group[i % k][nums[i]]++;
        }
        vector<vector<int>> dp(k, vector<int>(1024));
        for (int j = 0; j < 1024; j++) {
            dp[0][j] = groupcnt[0] - group[0][j];
        }
        for (int i = 1; i < k; i++) {
            int maxval = *min_element(dp[i - 1].begin(), dp[i - 1].end()) + groupcnt[i];
            fill(dp[i].begin(), dp[i].end(), maxval);
            for (auto [num, cnt]: group[i % k]) {
                for (int j = 0; j < 1024; j++) {
                    dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + groupcnt[i] - cnt);
                }
            }
        }
        return dp[k - 1][0];
    }
};
