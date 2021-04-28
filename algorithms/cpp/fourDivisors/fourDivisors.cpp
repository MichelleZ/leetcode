// Source: https://leetcode.com/problems/four-divisors/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int n: nums) {
            int r = sqrt(n);
            if (n <= 4 || r * r == n) continue;
            int cnt = 2;
            int sums = 1 + n;
            for (int d = 2; d <= r; d++) {
                if (n % d == 0) {
                    sums += n / d + d;
                    cnt += 2;
                }
            }
            if (cnt == 4) res += sums;
        }
        return res;
    }
};
