// Source: https://leetcode.com/problems/maximum-subarray/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for (int i = 1; i < nums.size(); i++) {
            int cur_sum = max(nums[i] + nums[i - 1], nums[i]);
            nums[i] = cur_sum;
        }
        int max_sum = nums[0];
        for (auto num: nums) {
            cout << num << ',';
            max_sum = max(max_sum, num);
        }
        return max_sum;
    }
};
