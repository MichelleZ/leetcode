// Source: https://leetcode.com/problems/array-nesting/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            while (nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
