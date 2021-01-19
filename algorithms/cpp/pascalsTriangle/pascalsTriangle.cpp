// Source: https://leetcode.com/problems/pascals-triangle/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>(0));
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = 1;
            res[i][i] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        return res;
    }
};
