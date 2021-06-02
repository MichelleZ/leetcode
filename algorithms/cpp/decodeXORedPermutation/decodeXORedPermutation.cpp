// Source: https://leetcode.com/problems/decode-xored-permutation/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> perm(n);
        for (int i = 1; i <= n; i++) {
            perm[0] ^= i;
        }
        for (int i = 1; i < n; i += 2) {
            perm[0] ^= encoded[i];
        }
        for (int i = 1; i < n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm;
    }
};
