// Source: https://leetcode.com/problems/number-of-good-pairs/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> cnt(101);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += cnt[nums[i]];
            cnt[nums[i]]++;
        }
        return res;
    }
};
