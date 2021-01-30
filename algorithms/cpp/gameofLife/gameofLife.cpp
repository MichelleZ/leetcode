// Source: https://leetcode.com/problems/game-of-life/
// Author: Miao Zhang
// Date:   2021-01-30

/***********************************************************
 * 1. cell = 1 live_counts < 2; live->dead
 * 2. cell = 1 live_counts == 2 or 3; live->live
 * 3. cell = 1 live_counts > 3; live->dead
 * 4. cell = 0 live_counts == 3; dead->live
 * Sum all, live state: (lives contains nine point)
 * (lives == 3) || (lives == 4 && cell == 1)
 * -> (lives == 3) || (lives - cell = 3)
 * result: original: 1, if result: 11, 1->1; if result: 01, 1->0
***********************************************************/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
                                    {0, 0}};
        int x, y;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = 0;
                for (auto d: dirs) {
                    x = i + d.first;
                    y = j + d.second;
                    if (x >= 0 && x < m && y >= 0 && y < n) lives += board[x][y] & 1;
                }
                if (lives == 3 || lives - board[i][j] == 3) board[i][j] |= 0b10; 
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
        return;
    }
};
