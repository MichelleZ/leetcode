// Source: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for (int num: nums) m[num]++;
        for (int num: nums) {
            if (m[num] < 1 || m[k - num] < 1 + (num + num == k)) continue;
            m[num]--;
            m[k - num]--;
            res++;
        }
        return res;
    }
};
