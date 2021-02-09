// Source: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: Miao Zhang
// Date:   2021-02-09

/****************************************************************
 * nums = [1, 5, 11, 15], sum(nums) = 22
 * dp = [1, 0, 0, .....0], dp.size() = 22 + 1
 * n = 1, 5, 11, 15
 * if dp[i] == 1, dp[i + n] = 1
 * if dp[22 / 2] == 1, return true
****************************************************************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = std::accumulate(nums.begin(), nums.end(), 0);
        if (sums % 2 != 0) return false;
        vector<int> dp(sums + 1, 0);
        dp[0] = 1;
        for (int n: nums) {
            for (int i = sums; i >= 0; i--) {
                if (dp[i]) dp[i + n] = 1;
            }
            if (dp[sums / 2]) return true;
        }
        return false;
    }
};
