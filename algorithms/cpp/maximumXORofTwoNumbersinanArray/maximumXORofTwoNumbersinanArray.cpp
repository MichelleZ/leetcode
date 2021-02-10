// Source: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Author: Miao Zhang
// Date:   2021-02-10

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask += 1 << i;
            set<int> s;
            for (auto n: nums) s.insert(n & mask);
            int tmp = res | 1 << i;
            for (auto p: s) {
                if (s.count(tmp ^ p)) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
