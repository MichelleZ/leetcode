// Source: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num: nums) freq[num]++;
        for (int num: nums) {
            if (freq[num] == 0) continue;
            if (need[num] > 0) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else {
                return false;
            }
            --freq[num];
        }
        return true;
    }
};
