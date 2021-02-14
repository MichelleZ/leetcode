// Source: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int res = 0;
        for (auto num: nums) {
            res += abs(num - nums[n / 2]);
        }
        return res;
    }
};
