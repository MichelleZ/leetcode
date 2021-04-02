// Source: https://leetcode.com/problems/number-of-enclaves/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int cnt = 0;
                if (!dfs(grid, i, j, cnt)) {
                    res += cnt;
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // true: arrive boundary
    // false: can not
    bool dfs(vector<vector<int>>& grid, int x, int y, int& cnt) {
        // arrive boundary
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return true;
        }
        // Beyond the scope of Statistics
        if (grid[x][y] == 0) return false;
        cnt++;
        grid[x][y] = 0;
        bool valid = false;
        for (auto d: dirs) {
            valid |= dfs(grid, x + d[0], y + d[1], cnt);
        }
        return valid;
    }
};
