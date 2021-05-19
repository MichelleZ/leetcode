// Source: https://leetcode.com/problems/make-sum-divisible-by-p/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int mod = accumulate(begin(nums), end(nums), 0LL) % p;
        if (mod == 0) return 0;
        unordered_map<int, int> m{{0, -1}};
        int sums = 0;
        int res = n;
        for (int i = 0; i < n; i++) {
            sums = (sums + nums[i]) % p;
            auto it = m.find((sums + p - mod) % p);
            if (it != m.end()) {
                res = min(res, i - it->second);
            }
            m[sums] = i;
        }
        return res;
    }
};
