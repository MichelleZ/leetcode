// Source: https://leetcode.com/problems/max-consecutive-ones/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt += 1;
                res = max(res, cnt);
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};
