// Source: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int makeStringSorted(string s) {
        int n = s.length();
        vector<long long> fact(n + 1, 1);
        vector<long long> inv(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % kMod;
            // Modular Multiplicative Inverse
            inv[i] = pow(fact[i], kMod - 2);
        }
        long long res = 0;
        vector<int> freq(26);
        for (char& c: s) freq[c - 'a']++;
        for (int i = 0; i < n - 1; i++) {
            int rank = 0;
            for (int j = 0; j < s[i] - 'a'; j++) {
                rank += freq[j];
            }
            long long cur = rank * fact[n - i - 1] % kMod;
            for (int j = 0; j < 26; j++) {
                cur = cur * inv[freq[j]] % kMod;
            }
            res = (res + cur) % kMod;
            freq[s[i] - 'a']--;
        }
        return res;
    }

private:
    const int kMod = 1e9 + 7;
    int64_t pow(int64_t base, int64_t exp) {
        int64_t res = 1;
        while (exp) {
            if (exp & 1) res = (res * base) % kMod;
            base = (base * base) % kMod;
            exp >>= 1;
        }
        return res;
    }
};
