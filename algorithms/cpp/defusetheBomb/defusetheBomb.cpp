// Source: https://leetcode.com/problems/defuse-the-bomb/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);
        int sign = k > 0 ? 1: -1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= abs(k); j++) {
                res[i] += code[(i + j * sign + n) % n];
            }
        }
        return res;
    }
};
