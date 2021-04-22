// Source: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Author: Miao Zhang
// Date:   2021-04-22

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        if (res.size() != n) res.push_back(0);
        return res;
    }
};
