// Source: https://leetcode.com/problems/distribute-repeating-integers/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (int num: nums) freq[num]++;
        vector<int> cnt;
        for (auto& [k, f]: freq)
            cnt.push_back(f);
        int n = cnt.size();
        int m = quantity.size();
        vector<int> sums(1 << m);
        for (int mask = 0; mask < 1 << m; mask++) {
            for (int j = 0; j < m; j++) {
                if (mask & ( 1 << j)) {
                    sums[mask] += quantity[j];
                }
            }
        }

       vector<vector<int>> dp(1 << m, vector<int>(n + 1));
       dp[0][0] = 1;
       for (int mask = 0; mask < 1 << m; ++mask) {
           for (int j = 0; j < n; j++) {
               dp[mask][j + 1] |= dp[mask][j];
               for (int cur = mask; cur; cur = (cur - 1) & mask)
                   if (sums[cur] <= cnt[j] && dp[mask ^ cur][j])
                       dp[mask][j + 1] = 1;
            }
       }
       return dp[(1 << m) - 1][n];
    }
};
