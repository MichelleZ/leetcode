// Source: https://leetcode.com/problems/longest-mountain-in-array/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> inc(arr.size());
        vector<int> dec(arr.size());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (inc[i] && dec[i]) {
                res = max(res, inc[i] + dec[i] + 1);
            }
        }
        return res;
    }
};
