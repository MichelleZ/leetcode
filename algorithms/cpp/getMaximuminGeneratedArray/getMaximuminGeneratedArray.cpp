// Source: https://leetcode.com/problems/get-maximum-in-generated-array/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> res(n + 1);
        res[0] = 0;
        if (n > 0) res[1] = 1;
        for (int i = 1; i * 2 <= n; i++) {
            res[2 * i] = res[i];
            if (i * 2 + 1 <= n) {
                res[2 * i + 1] = res[i] + res[i + 1];
            }
        }
        return *max_element(begin(res), end(res));
    }
};
