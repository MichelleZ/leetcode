// Source: https://leetcode.com/problems/array-partition-i/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};
