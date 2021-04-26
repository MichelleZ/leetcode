// Source: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [] (const int& a, const int& b) {
            int bina = __builtin_popcount(a);
            int binb = __builtin_popcount(b);
            return bina < binb || (bina == binb && a < b);
        });
        return arr;
    }
};
