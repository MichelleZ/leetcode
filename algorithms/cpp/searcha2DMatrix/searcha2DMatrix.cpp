// Source: https://leetcode.com/problems/search-a-2d-matrix/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;
        while (true) {
            if (r < m && c >= 0) {
                if (matrix[r][c] == target) {
                    return true;
                } else if (matrix[r][c] > target) {
                    c--;
                } else {
                    r++;
                }
            } else {
                return false;
            }
        }
    }
};
