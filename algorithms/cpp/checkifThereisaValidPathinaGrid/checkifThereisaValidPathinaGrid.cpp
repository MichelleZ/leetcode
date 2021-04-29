// Source: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/submissions/
// Author: Miao Zhang
// Date:   2021-04-28

/************************************************************
 *     0
 *     |
 * 3--- ---1
 *     |
 *     2
 * 1: left or right  2: upper or lowe 3: left lower 4: right lower
 * 5: left upper 6: right upper
************************************************************/
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // refer the picture on the right side, street1-6 is key
        vector<vector<int>> cell{{}, {1, 3}, {0, 2}, {2, 3}, {1, 2}, {0, 3}, {0, 1}};
        // original dir indx-> next dir
        vector<vector<int>> dirs{{-1, 0, 2}, {0, 1, 3}, {1, 0, 0}, {0, -1, 1}};
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;
        q.push(0);
        vector<int> seen(m * n);
        seen[0] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int x = cur / n;
            int y = cur % n;
            if (x == m - 1 && y == n - 1) return true;
            for (auto& c: cell[grid[x][y]]) {
                int tx = x + dirs[c][0];
                int ty = y + dirs[c][1];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || seen[tx * n + ty] || find(begin(cell[grid[tx][ty]]), end(cell[grid[tx][ty]]), dirs[c][2]) ==  cell[grid[tx][ty]].end())
                    continue;
                seen[tx * n + ty] = 1;
                q.push(tx * n + ty);
            }
        }
        return false;
    }
};
