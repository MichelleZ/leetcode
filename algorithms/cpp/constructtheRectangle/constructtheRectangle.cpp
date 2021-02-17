// Source: https://leetcode.com/problems/construct-the-rectangle/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int w = sqrt(area); w >= 0; w--) {
            if (area % w == 0) {
                return {area / w, w};
            }
        }
        return {-1, -1};
    }
};
