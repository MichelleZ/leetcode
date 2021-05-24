// Source: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int numberOfSets(int n, int k) {
        int kMod = 1e9 + 7;
        // C(n, m) = C(n - 1, m - 1) + C(n - 1, m)
        // C(n + k - 1, 2 * k)
        vector<vector<int>> C(n + k, vector<int>(n + k));
        for (int i = 0; i < n + k; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % kMod;
            }
        }

        return C[n + k - 1][2 * k] % kMod;
    }
};
