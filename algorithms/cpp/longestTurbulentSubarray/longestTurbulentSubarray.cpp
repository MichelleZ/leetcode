// Source: https://leetcode.com/problems/longest-turbulent-subarray/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> up(arr.size(), 1);
        vector<int> down(arr.size(), 1);
        int res = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) up[i] = down[i - 1] + 1;
            if (arr[i] < arr[i - 1]) down[i] = up[i - 1] + 1;
            res = max(res, max(up[i], down[i]));
        }
        return res;
    }
};
