// Source: https://leetcode.com/problems/numbers-with-repeated-digits/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> digits;
        for (int x = N + 1; x > 0; x /= 10) {
            digits.insert(digits.begin(), x % 10);
        }
        int res = 0;
        int len = digits.size();
        // 1, 2, 3, len - 1
        for (int i = 1; i < len; i++) {
            res += 9 * A(9, i - 1);
        }
        unordered_set<int> visited;
        for (int i = 0; i < len; i++) {
            for (int j = i > 0 ? 0 : 1; j < digits[i]; j++) {
                if (visited.count(j)) continue;
                res += A(9 - i, len - i - 1);
            }
            if (visited.count(digits[i])) break;
            visited.insert(digits[i]);
        }
        return N - res;
    }

private:
    int A(int m, int n) {
        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
    }
};
