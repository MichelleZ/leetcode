// Source: https://leetcode.com/problems/move-zeroes/
// Author: Miao Zhang
// Date:   2021-01-30

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
