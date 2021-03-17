// Source: https://leetcode.com/problems/magic-squares-in-grid/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                res += magic(grid, i, j);
            }
        }
        return res;
    }

private:
    int magic(const vector<vector<int>>& grid, int x, int y) {
        vector<int> rows(3);
        vector<int> cols(3);
        vector<int> corrects(3, 15);
        vector<int> cnts(10, 0);
        int dia = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[x + i][y + j];
                if (val < 0 || val > 9) return false;
                if (++cnts[val] > 1) return false;
                rows[i] += val;
                cols[j] += val;
                if (i == j) dia += val;
            }
        }
        return rows == corrects && cols == corrects && dia == 15;
    }
};
