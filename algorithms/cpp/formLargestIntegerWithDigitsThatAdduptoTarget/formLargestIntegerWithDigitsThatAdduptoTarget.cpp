// Source: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// Author: Miao Zhang
// Date:   2021-05-07

/***************************************************************
 * dp[target]: largest number when cost == target
 * dp[target] = max(dp(target - d) + cost[d])
***************************************************************/
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        for (int t = 1; t <= target; t++) {
            for (int d = 1; d <= 9; d++) {
                int s = t - cost[d - 1];
                if (s < 0 || dp[s] == "0" || dp[s].length() + 1 < dp[t].length()) continue;
                dp[t] = to_string(d) + dp[s];
            }
        }
        return dp[target];
    }
};
