// Source: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int res = 0;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                cnt++;
            res += cnt;
        }
        return res;
    }
};
