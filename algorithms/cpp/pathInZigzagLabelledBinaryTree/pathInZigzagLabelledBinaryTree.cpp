// Source: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-09

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log(label) / log(2) + 1;
        cout << level << endl;
        vector<int> path(level);
        while (label) {
            path[level-1] = label;
            label = pow(2, level) - 1 - label + pow(2, level - 1);
            label >>= 1;
            level--;
        }
        return path;
    }
};
