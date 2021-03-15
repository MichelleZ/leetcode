// Source: https://leetcode.com/problems/making-a-large-island/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        color = 1;
        m = grid.size();
        n = grid[0].size();
        unordered_map<int, int> areas; // color: area
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ++color;
                    areas[color] = getArea(grid, i, j);
                    res = max(res, areas[color]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    for (int color: set<int>{getColor(grid, i, j - 1),
                                             getColor(grid, i, j + 1),
                                             getColor(grid, i - 1, j),
                                             getColor(grid, i + 1, j)}) {
                        area += areas[color];
                    }
                    res = max(res, area);
                }
            }
        }
        return res;
    }

private:
    int m;
    int n;
    int color;

    int getArea(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = color;
        return 1 + getArea(grid, i - 1, j) + getArea(grid, i + 1, j) \
               + getArea(grid, i, j - 1) + getArea(grid, i, j + 1);
    }

    int getColor(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        return grid[i][j];
    }
};
