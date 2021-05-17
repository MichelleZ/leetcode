// Source: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i + m < n; i++) {
            if (arr[i] == arr[i + m]) {
                if (++cnt == (k - 1) * m)
                    return true;
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
