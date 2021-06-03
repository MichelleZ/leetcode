// Source: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool isRotate = nums[0] >= nums[n - 1];
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (isRotate) {
                    isRotate = false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
