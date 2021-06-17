// Source: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for (auto r: ranges) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }
        int cur = 0;
        for (int i = 1; i <= 50; i++) {
            cur += diff[i];
            if (i >= left && i <= right && cur <= 0)
                return false;
        }
        return true;
    }
};
