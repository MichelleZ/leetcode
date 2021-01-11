// Source: https://leetcode.com/problems/jump-game-ii/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int steps = 0;
        int pos = 0;
        int pre = 0;
        while (cur < n - 1) {
            steps += 1;
            pre = cur;
            while (pos <= pre) {
                cur = max(cur, pos + nums[pos]);
                pos += 1;
            }
        }
        return steps;
    }
};
