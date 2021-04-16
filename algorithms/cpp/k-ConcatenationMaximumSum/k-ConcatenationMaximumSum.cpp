// Source: https://leetcode.com/problems/k-concatenation-maximum-sum/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        auto maxSum = [&arr] (int k) {
            long sum = 0;
            long res = 0;
            for (int i = 0; i < k; i++) {
                for (long a: arr) {
                    sum = max(0L, sum += a);
                    res = max(res, sum);
                }
            }
            return res;
        };

        int kMod = 1e9 + 7;
        if (k < 3) return maxSum(k) % kMod;
        long res1 = maxSum(1);
        long res2 = maxSum(2);
        long sum = accumulate(begin(arr), end(arr), 0L);
        return max({res1, res2, res2 + sum * (k - 2)}) % kMod;
    }
};
