// Source: https://leetcode.com/problems/duplicate-zeros/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n) arr[j] = arr[i];
            if (arr[i] == 0 && --j < n) arr[j] = 0;
        }
    }
};
