// Source: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = ops(m, nums);
            if (cnt <= maxOperations) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

private:
    int ops(int m, vector<int>& nums) {
        int res = 0;
        for (int& x: nums) {
            res += (x - 1) / m;
        }
        return res;
    }
};
