// Source: https://leetcode.com/problems/sort-array-by-parity-ii/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j = 1;
        for (int i = 0; i < nums.size(); i+=2) {
            if (nums[i] % 2) {
                while (nums[j] % 2) j += 2;
                swap(nums[i], nums[j]);
                j += 2;
            }
        }
        return nums;
    }
};
