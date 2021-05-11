// Source: https://leetcode.com/problems/path-crossing/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> s;
        int x = 0;
        int y = 0;
        s.insert(x * 10000 + y);
        for (char& p: path) {
            if (p == 'N') {
                y++;
            } else if (p == 'S') {
                y--;
            } else if (p == 'E') {
                x++;
            } else {
                x--;
            }
            if (!s.insert(x * 10000 + y).second) {
                return true;
            }
        }
        return false;
    }
};
