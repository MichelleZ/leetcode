// Source: https://leetcode.com/problems/count-servers-that-communicate/
// Author: Miao Zhang
// Date:   2021-04-20

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += (rows[i] > 1 || cols[j] > 1) ? grid[i][j] : 0;
            }
        }
        return res;
    }
};
