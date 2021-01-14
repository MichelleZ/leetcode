// Source: https://leetcode.com/problems/word-search/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
        if (word.size() == 0) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        bool res = dfs(board, word.substr(1, word.size() - 1), i + 1, j) || dfs(board, word.substr(1, word.size() - 1), i - 1, j) || dfs(board, word.substr(1, word.size() - 1), i, j + 1) || dfs(board, word.substr(1, word.size() - 1), i, j - 1);
        board[i][j] = tmp;
        return res;
    }
};
