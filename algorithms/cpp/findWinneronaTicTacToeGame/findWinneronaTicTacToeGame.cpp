// Source: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> grid(3, vector<string>(3, "#"));
        bool A = true;
        for (const auto& move: moves) {
            grid[move[0]][move[1]] = A ? "A" : "B";
            A = !A;
        }
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != "#")
                return grid[i][0];
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != "#")
                return grid[0][i];
        }
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != "#")
            return grid[0][0];
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != "#")
            return grid[0][2];
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
