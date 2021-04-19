// Source: https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int dx = coordinates[1][0] - x1;
        int dy = coordinates[1][1] - y1;
        for (int i = 2; i < n; i++) {
            int tx = coordinates[i][0] - x1;
            int ty = coordinates[i][1] - y1;
            if (tx * dy - ty * dx) {
                return false;
            }
        }
        return true;
    }
};
