// Source: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        for (int i = 1; i < target.size(); i++) {
            res += max(0, target[i] - target[i - 1]);
        }
        return res;
    }
};
