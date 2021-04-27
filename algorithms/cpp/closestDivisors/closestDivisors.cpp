// Source: https://leetcode.com/problems/closest-divisors/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    vector<int> closestDivisors(int num) {
        auto divisors = [] (int n) {
            for (int i = sqrt(n); i >= 2; i--) {
                if (n % i == 0)
                    return vector<int>{i, n / i};
            }
            return vector<int>{1, n};
        };
        vector<int> res1 = divisors(num + 1);
        vector<int> res2 = divisors(num + 2);
        return abs(res1[0] - res1[1]) < abs(res2[0] - res2[1]) ? res1 : res2;
    }
};
