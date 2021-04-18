// Source: https://leetcode.com/problems/queens-that-can-attack-the-king/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> grid(8, vector<int>(8));
        for (auto q: queens) {
            grid[q[0]][q[1]] = 1;
        }
        vector<vector<int>> res;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto d: dirs) {
            int x = king[0] + d[0];
            int y = king[1] + d[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (grid[x][y] == 1) {
                    res.push_back({x, y});
                    break;
                }
                x += d[0];
                y += d[1];
            }
        }
        return res;
    }
};
