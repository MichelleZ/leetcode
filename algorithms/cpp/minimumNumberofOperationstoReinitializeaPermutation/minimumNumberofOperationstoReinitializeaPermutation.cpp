// Source: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        iota(begin(perm), end(perm), 0);
        vector<int> arr(n);
        int res = 0;
        bool flag = true;
        while (flag && ++res) {
            flag = false;
            for (int i = 0; i < n; i++) {
                arr[i] = i & 1 ? perm[n / 2 + (i - 1) / 2] : perm[i / 2];
                flag |= arr[i] != i;
            }
            swap(perm, arr);
        }
        return res;
    }
};
