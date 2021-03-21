// Source: https://leetcode.com/problems/decoded-string-at-index/
// Author: Miao Zhang
// Date:   2021-03-21

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long len = 0;
        for (auto& c: S) {
            if (isdigit(c)) {
                len *= c - '0';
            } else {
                len++;
            }
        }

        for (int i = S.size() - 1; i >= 0; i--) {
            K %= len;
            if (K == 0 && isalpha(S[i])) {
                return (string)"" + S[i];
            }
            if (isdigit(S[i])) {
                len /= (S[i] - '0');
            } else {
                len--;
            }
        }
        return "";
    }
};
