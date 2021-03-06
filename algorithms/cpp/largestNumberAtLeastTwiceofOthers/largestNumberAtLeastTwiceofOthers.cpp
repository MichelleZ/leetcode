// Source: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Author: Miao Zhang
// Date:   2021-03-06

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int firstidx = -1;
        int secondidx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) {
                second = first;
                secondidx = firstidx;
                first = nums[i];
                firstidx = i;
            } else if (nums[i] > second && nums[i] < first) {
                second = nums[i];
                secondidx = i;
            }
        }
        if (first >= (2 * second)) return firstidx;
        return -1;
    }
};
