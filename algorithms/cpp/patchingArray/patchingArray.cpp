// Source: https://leetcode.com/problems/patching-array/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        int res = 0;
        long known_num = 1;
        while (known_num <= n) {
            if (i < nums.size() && nums[i] <= known_num) {
                known_num += nums[i++];
            } else {
                known_num += known_num;
                res += 1;
            }
        }
        return res;
    }
};
