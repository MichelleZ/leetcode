// Source: https://leetcode.com/problems/number-of-different-subsequences-gcds/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxnum = *max_element(begin(nums), end(nums));
        vector<bool> g(maxnum + 1, false);
        for (int num: nums) g[num] = true;
        int res = 0;
        for (int i = 1; i <= maxnum; i++) {
            int gcd = 0;
            for (int j = i; j <= maxnum; j += i) {
                if (g[j] == true) {
                    gcd = __gcd(gcd, j);
                }
            }
            if (gcd == i) res++;
        }
        return res;
    }
};
