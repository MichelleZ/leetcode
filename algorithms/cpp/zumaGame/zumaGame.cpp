// Source: https://leetcode.com/problems/zuma-game/
// Author: Miao Zhang
// Date:   2021-02-16

class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> h(128, 0);
        for (char color: hand) h[color]++;
        return dfs(board, h);
    }

private:
    int dfs(string& board, vector<int>& hand) {
        if (board.empty()) return 0;
        int res = INT_MAX;
        int i = 0;
        int j = 0;
        while (i < board.size()) {
            while (j < board.size() && board[i] == board[j]) j++;
            // i ~ j-1 same
            char color = board[i];
            int b = max(0, 3 - (j - i));
            if (hand[color] >= b) {
                string newb = update(board.substr(0, i) + board.substr(j));
                hand[color] -= b;
                int ans = dfs(newb, hand);
                if (ans >= 0) {
                    res = min(res, ans + b);
                }
                hand[color] += b;
            }
            i = j;
        }
        if (update(board).empty()) return res;
        return res == INT_MAX ? -1 : res;
    }

    // "ywwrrrwwyy" -> "ywwwwyy" -> "yyy" -> ""
    string update(string board) {
        int i = 0;
        while (i < board.size()) {
            int j = i;
            while (j < board.size() && board[i] == board[j]) j++;
            if (j - i >= 3) {
                board = board.substr(0, i) + board.substr(j);
                i = 0;
            } else {
                i++;
            }
        }
        return board;
    }

};
