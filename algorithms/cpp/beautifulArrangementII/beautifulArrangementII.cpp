// Source: https://leetcode.com/problems/beautiful-arrangement-ii/
// Author: Miao Zhang
// Date:   2021-02-27

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1;
        int r = n;
        while (l <= r) {
            if (k > 1) {
                if (k % 2 == 1) {
                    res.push_back(l++);
                } else {
                    res.push_back(r--);
                }
                k--;
            } else {
                res.push_back(l++);
            }
        }
        return res;
    }
};
