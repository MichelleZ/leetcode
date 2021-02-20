// Source: https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        for (auto n: nums) dic[n]++;
        int res = 0;
        for (auto &it: dic) {
            if (k > 0 && dic.count(it.first + k)) res++;
            if (k == 0 && it.second > 1) res++;
        }
        return res;
    }
};
