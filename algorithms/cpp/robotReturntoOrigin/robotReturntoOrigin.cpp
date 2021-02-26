// Source: https://leetcode.com/problems/robot-return-to-origin/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (const char m: moves) {
            if (m == 'U') {
                y++;
            } else if (m == 'D') {
                y--;
            } else if (m == 'L') {
                x--;
            } else if (m == 'R') {
                x++;
            }
        }
        return x == 0 && y == 0;
    }
};
