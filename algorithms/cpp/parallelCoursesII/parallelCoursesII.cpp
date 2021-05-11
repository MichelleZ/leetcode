// Source: https://leetcode.com/problems/parallel-courses-ii/
// Author: Miao Zhang
// Date:   2021-05-11

/*****************************************************************
 * dp[state] = min(dp[state], dp[preState] + 1) fdsa
 * preState -> state:
 * 1. prevState is subset of state
 * 2. countOne(state) - countOne(preState) <= k
 * 3. prevState must contain prerequisites of state, subset > prereq[state]
*****************************************************************/
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> preCourse(n, 0);
        for (auto d: dependencies) {
            preCourse[d[1] - 1] |= 1 << (d[0] - 1);
        }
        vector<int> prereq(1 << n, 0);
        for (int state = 0; state < (1 << n); state++) {
            prereq[state] = 0;
            for (int i = 0; i < n; i++) {
                if ((state >> i) & 1) {
                    prereq[state] |= preCourse[i];
                }
            }
        }
        vector<int> dp(1 << n, INT_MAX / 2);
        dp[0] = 0;
        for (int state = 0; state < (1 << n); state++) {
            for (int subset = state; subset >= 0; subset = (subset - 1) & state) {
                if (__builtin_popcount(state) - __builtin_popcount(subset) <= k && (subset & prereq[state]) == prereq[state]) {
                    dp[state] = min(dp[state], dp[subset] + 1);
                }
                if (subset == 0) break;
            }
        }
        return dp[(1 << n) - 1];
    }
};
