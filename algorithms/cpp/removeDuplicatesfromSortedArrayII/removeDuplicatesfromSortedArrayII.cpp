// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto num: nums) {
            if (i < 2 || num != nums[i - 2]) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};
