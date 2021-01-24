// Source: https://leetcode.com/problems/majority-element/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
