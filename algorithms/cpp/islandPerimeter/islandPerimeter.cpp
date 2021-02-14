// Source: https://leetcode.com/problems/island-perimeter/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int recnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    res++;
                    if (i > 0 && grid[i - 1][j]) {
                        recnt++;
                    }
                    if (j > 0 && grid[i][j - 1]) {
                        recnt++;
                    }
                    if (i + 1 < m && grid[i + 1][j]) {
                        recnt++;
                    }
                    if (j + 1 < n && grid[i][j + 1]) {
                        recnt++;
                    }
                }
            }
        }
        return res * 4 - recnt;
    }
};
