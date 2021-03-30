// Source: https://leetcode.com/problems/largest-perimeter-triangle/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
