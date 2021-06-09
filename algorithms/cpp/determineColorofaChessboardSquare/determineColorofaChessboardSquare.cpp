// Source: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') + (coordinates[1] - '0')) % 2 == 0;
    }
};
