// Source: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 2);
        for (int num: nums) {
            ans[min(n, num)]++;
        }
        for (int i = n; i >= 0; i--) {
            if ((ans[i] += ans[i + 1]) == i)
                return i;
        }
        return -1;
    }
};
