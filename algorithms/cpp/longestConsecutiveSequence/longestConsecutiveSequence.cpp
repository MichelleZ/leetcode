// Source: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dicts;
        int res = 0;
        for (auto num: nums) {
            if (dicts.count(num)) continue;
            int left = dicts.find(num - 1) != dicts.end() ? dicts.find(num - 1)->second : 0;
            int right = dicts.find(num + 1) != dicts.end() ? dicts.find(num + 1)->second : 0;
            int length = left + right + 1;
            dicts[num] = dicts[num - left] = dicts[num + right] = length;
            
            res = max(res, length);
        }
        return res;
    }
};
