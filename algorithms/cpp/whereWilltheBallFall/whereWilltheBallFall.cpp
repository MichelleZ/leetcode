// Source: https://leetcode.com/problems/where-will-the-ball-fall/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto check = [&] (int j) {
            for (int i = 0; i < m; i++) {
                if ((grid[i][j] == 1 && (j == n - 1 || grid[i][j + 1] == -1)) || (grid[i][j] == -1 && (j == 0 || grid[i][j - 1] == 1)))
                    return -1;
                else
                    j += grid[i][j];
            }
            return j;
        };
        vector<int> res(n);
        for (int j = 0; j < n; j++) {
            res[j] = check(j);
        }
        return res;
    }
};
