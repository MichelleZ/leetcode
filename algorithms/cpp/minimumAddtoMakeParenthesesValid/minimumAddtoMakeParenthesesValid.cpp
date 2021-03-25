// Source: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    int minAddToMakeValid(string S) {
        int right = 0;
        int left = 0;
        for (auto& c: S) {
            left += (c == '(' ? 1 : -1);
            if (left == -1) {
                right += 1;
                left += 1;
            }
        }
        return left + right;
    }
};
