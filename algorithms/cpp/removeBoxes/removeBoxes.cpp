// Source: https://leetcode.com/problems/remove-boxes/
// Author: Miao Zhang
// Date:   2021-02-21

/****************************************************************
 * dp[i][j][k] = max(dp[i][j - 1][0] + (k + 1) * (k + 1),
 *                   dp[i][p][k + 1] + dp[p + 1][j - 1][0])
 * "ABACA|AAAA"
 * case 1: dp("ABAC") + score("AAAAA") drop j and the tail.
 * case 2: box[i] == box[r], l <= i < r, try all break points
 * max({dp("A|AAAAA") + dp("BAC")}, {dp("ABA|AAAAA") + dp("C")})
****************************************************************/
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memo_ = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n)));
        return dfs(boxes, 0, n - 1, 0);
    }

private:
    vector<vector<vector<int>>> memo_;

    int dfs(vector<int>& boxes, int i, int j, int k) {
        if (i > j) return 0;
        if (memo_[i][j][k] > 0) return memo_[i][j][k];
        memo_[i][j][k] = dfs(boxes, i, j - 1, 0) + (k + 1) * (k + 1);
        for (int r = i; r < j; r++){
            if (boxes[r] == boxes[j]) {
                memo_[i][j][k] = max(memo_[i][j][k], dfs(boxes, i, r, k + 1) + dfs(boxes, r + 1, j - 1, 0));
            }
        }
        return memo_[i][j][k];
    }
};
