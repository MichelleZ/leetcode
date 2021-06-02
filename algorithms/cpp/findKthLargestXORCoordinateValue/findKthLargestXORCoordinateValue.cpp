// Source: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp.push_back(matrix[i][j]
                             ^= (i ? matrix[i - 1][j] : 0)
                              ^ (j ? matrix[i][j - 1] : 0)
                              ^ (i * j ? matrix[i - 1][j - 1] : 0));
            }
        }
        nth_element(begin(dp), begin(dp) + k - 1, end(dp), greater<int>());
        return dp[k - 1];
    }
};
