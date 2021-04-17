// Source: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int a: arr) {
            dp[a] = dp[a - difference] + 1;
            res = max(res, dp[a]);
        }
        return res;
    }
};
