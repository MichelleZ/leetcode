// Source: https://leetcode.com/problems/total-hamming-distance/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int cnt0 = 0;
            int cnt1 = 0;
            int mask = 1 << i;
            for (int n: nums) {
                if (n & mask) cnt1++;
                else cnt0++;
            }
            res += cnt0 * cnt1;
        }
        return res;
    }
};
