// Source: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod(k);
        for (int a: arr) {
            mod[(a % k + k) % k]++;
        }
        for (int i = 1; i < k; i++) {
            if (mod[i] != mod[k - i]) return false;
        }
        return mod[0] % 2 == 0;
    }
};
