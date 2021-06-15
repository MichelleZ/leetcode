// Source: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    tmp ^= nums[j];
                }
            }
            res += tmp;
        }
        return res;
    }
};
