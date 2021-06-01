// Source: https://leetcode.com/problems/tuple-with-same-product/
// Author: Miao Zhang
// Date:   2021-06-01

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        int res = 0;
        for (auto& v: m) {
            res += v.second * (v.second - 1) / 2;
        }
        return res * 8;
    }
};
