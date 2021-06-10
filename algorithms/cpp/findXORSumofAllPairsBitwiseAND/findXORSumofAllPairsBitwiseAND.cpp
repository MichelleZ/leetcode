// Source: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int resa = 0;
        int resb = 0;
        for (int& a: arr1) resa ^= a;
        for (int& a: arr2) resb ^= a;
        return resa & resb;
    }
};
