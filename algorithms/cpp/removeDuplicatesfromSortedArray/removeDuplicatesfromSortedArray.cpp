// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        return j;
    }
};
