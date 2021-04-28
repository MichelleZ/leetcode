// Source: https://leetcode.com/problems/pizza-with-3n-slices/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> s1(begin(slices) + 1, end(slices));
        vector<int> s2 (begin(slices), end(slices) - 1);
        int res1 = cal(s1);
        int res2 = cal(s2);
        return max(res1, res2);
    }

private:
    int cal(vector<int>& slices) {
        int n = slices.size();
        int choose = (n + 1) / 3;
        vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < choose + 1; j++) {
                dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
            }
        }
        return dp[n][choose];
    }
};
