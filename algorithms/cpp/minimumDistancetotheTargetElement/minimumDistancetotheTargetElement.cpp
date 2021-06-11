// Source: https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                res = min(res, abs(i - start));
        }
        return res;
    }
};
