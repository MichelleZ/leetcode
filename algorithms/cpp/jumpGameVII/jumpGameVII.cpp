// Source: https://leetcode.com/problems/jump-game-vii/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n), sums(n);
        dp[0] = 1;
        for (int i = 0; i < minJump; i++) {
            sums[i] = 1;
        }
        for (int i = minJump; i < n; i++) {
            int l = i - maxJump, r = i - minJump;
            if (s[i] == '0') {
                int total = sums[r] - (l <= 0 ? 0 : sums[l - 1]);
                dp[i] = (total != 0);
            }
            sums[i] = sums[i - 1] + dp[i];
        }
        return dp[n - 1];
    }
};
