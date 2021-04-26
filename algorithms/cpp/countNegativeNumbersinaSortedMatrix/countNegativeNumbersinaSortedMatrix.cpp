// Source: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                res += m - i;
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};
