// Source: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
// Author: Miao Zhang
// Date:   2021-05-15

/***************************************************
 * dp(i): min steps to eat i oranges
 * dp(n) = 1 + min{dp(n - 1),
 *                 dp(n / 2) if n % 2 == 0
 *                 dp(n / 3) if n % 3 == 0}
 * dp(n) = 1 + min{n % 2 + dp(n / 2), n % 3 + dp(n / 3)}
 * dp(0) = 0 dp(1) = 1
***************************************************/
class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> cache;
        function<int(int)> dp = [&] (int n) {
            if (n <= 1) return n;
            auto it = cache.find(n);
            if (it != cache.end()) return it->second;
            return cache[n] = 1 + min(n % 2 + dp(n / 2), n % 3 + dp(n / 3));
        };
        return dp(n);
    }
};
