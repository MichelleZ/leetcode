// Source: https://leetcode.com/problems/subarray-sum-equals-k/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> cnts{{0, 1}};
        int cur_sum = 0;
        int res = 0;
        for (const int num: nums) {
            cur_sum += num;
            res += cnts[cur_sum - k];
            cnts[cur_sum]++;
        }
        return res;
    }
};
