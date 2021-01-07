// Source: https://leetcode.com/problems/remove-element/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (auto num: nums) {
            if (num != val) {
                nums[j] = num;
                j++;
            }
        }
        return j;
    }
};
