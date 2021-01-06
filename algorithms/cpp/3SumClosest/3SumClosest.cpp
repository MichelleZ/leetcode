// Source: https://leetcode.com/problems/3sum-closest/
// Author: Miao Zhang
// Date:   2021-01-05

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (abs(res - target) > abs(tmp - target)) {
                    res = tmp;
                } else if (tmp < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
