// Source: https://leetcode.com/problems/escape-the-ghosts/
// Author: Miao Zhang
// Date:   2021-03-10

// Manhattan Distance
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int steps = abs(target[0]) + abs(target[1]);
        for (auto& g: ghosts) {
            if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= steps) return false;
        }
        return true;
    }
};
