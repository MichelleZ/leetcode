// Source: https://leetcode.com/problems/sum-of-unique-elements/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num: nums) {
            m[num]++;
        }
        int res = 0;
        for (auto& [k, v]: m) {
            if (v == 1) {
                res += k;
            }
        }
        return res;
    }
};
