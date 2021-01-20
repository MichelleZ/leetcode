// Source: https://leetcode.com/problems/surrounded-regions/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        vector<pair<int, int>> dirs;
        dirs.push_back(make_pair(1, 0));
        dirs.push_back(make_pair(-1, 0));
        dirs.push_back(make_pair(0, 1));
        dirs.push_back(make_pair(0, -1));
        for (auto d: dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O') {
                dfs(board, x, y);
            }
        }
        
    }
};
