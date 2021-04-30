// Source: https://leetcode.com/problems/stone-game-iii/
// Author: Miao Zhang
// Date:   2021-04-30

/**************************************************************
 * dp[i] i, i+1, i+2,....n-1
 * dp[i] = value[i] - dp[i + 1]
 *         value[i] + value[i + 1] - dp[i + 2]
 *         value[i] + valud[i + 1] + value[i + 2] - dp[i + 3]
 * dp[i] = max(sum(i, j - 1) - dp[j]) i + 1 <= j <= i + 3
**************************************************************/
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int presum = 0;
            for (int j = i + 1; j <= i + 3 && j < n + 1; j++) {
                presum += stoneValue[j - 1];
                dp[i] = max(dp[i], presum - dp[j]);
            }
        }
        for(auto& x: dp) cout << x << endl;
        return dp[0] < 0 ? "Bob" : (dp[0] > 0 ? "Alice" : "Tie");
    }
};
