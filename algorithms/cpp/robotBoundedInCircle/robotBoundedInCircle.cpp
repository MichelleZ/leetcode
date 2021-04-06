// Source: https://leetcode.com/problems/robot-bounded-in-circle/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int d = 0;
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{-1, 0, 1, 0};
        for (char c: instructions) {
            if (c == 'G') {
                x += dx[d];
                y += dy[d];
            } else if (c == 'L') {
                d = (d - 1 + 4) % 4;
            } else {
                d = (d + 1) % 4;
            }
        }
        return x == 0 && y == 0 || d;
    }
};
