// Source: https://leetcode.com/problems/rectangle-overlap/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }
        return rec1[0] < rec2[2] && rec1[1] < rec2[3] &&
               rec2[0] < rec1[2] && rec2[1] < rec1[3];
    }
};
