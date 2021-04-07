// Source: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                if (matrix[i][0] == 0)
                    row += to_string(matrix[i][j]);
                else
                    row += to_string(!matrix[i][j]);
            }
            cnt[row]++;
            res = max(res, cnt[row]);
        }
        return res;
    }
};
