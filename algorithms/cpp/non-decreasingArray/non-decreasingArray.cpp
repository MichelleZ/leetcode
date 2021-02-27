// Source: https://leetcode.com/problems/non-decreasing-array/
// Author: Miao Zhang
// Date:   2021-02-27

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                cnt++;
                if (i == 1 or nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return cnt <= 1;
    }
};
