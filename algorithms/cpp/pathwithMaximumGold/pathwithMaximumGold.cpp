// Source: https://leetcode.com/problems/path-with-maximum-gold/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
                return 0;
            int tmp = 0;
            swap(tmp, grid[i][j]);
            int res = tmp + max({dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1)});
            swap(grid[i][j], tmp);
            return res;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};
