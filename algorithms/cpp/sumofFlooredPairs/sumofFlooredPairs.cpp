// Source: https://leetcode.com/problems/sum-of-floored-pairs/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int kMod = 1e9 + 7;
        int upper = *max_element(begin(nums), end(nums));
        vector<int> cnt(upper + 1);
        for (int num: nums) cnt[num]++;
        vector<int> sums(upper + 1);
        for (int i = 1; i <= upper; i++) {
            sums[i] = sums[i - 1] + cnt[i];
        }
        long long res = 0;
        for (int y = 1; y <= upper; y++) {
            if (cnt[y]) {
                for (int d = 1; d * y <= upper; d++) {
                    res += (long long)cnt[y] * d * (sums[min((d + 1) * y - 1, upper)] - sums[d * y - 1]);
                }
            }
        }
        return res % kMod;
    }
};
