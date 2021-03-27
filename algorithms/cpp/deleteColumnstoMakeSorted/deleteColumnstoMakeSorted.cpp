// Source: https://leetcode.com/problems/delete-columns-to-make-sorted/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int j = 0; j < strs[0].size(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
