// Source: https://leetcode.com/problems/shuffle-the-array/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);
        int i = 0;
        int l = 0;
        int r = n;
        while (l < n) {
            res[i++] = nums[l++];
            res[i++] = nums[r++];
        }
        return res;
    }
};
