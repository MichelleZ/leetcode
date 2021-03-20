// Source: https://leetcode.com/problems/walking-robot-simulation/
// Author: Miao Zhang
// Date:   2021-03-20

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int direction = 1;
        unordered_map<int, unordered_set<int>> obs;
        for (auto o: obstacles) obs[o[0]].insert(o[1]);
        int res = 0;
        for (int c: commands) {
            if (c == -2) {
                direction = (direction - 1 + 4) % 4;
            } else if (c == -1) {
                direction = (direction + 1) % 4;
            } else {
                while (c--) {
                    int x = i + dirs[direction][0];
                    int y = j + dirs[direction][1];
                    if (obs.count(x) && obs.at(x).count(y)) break;
                    i = x;
                    j = y;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};
