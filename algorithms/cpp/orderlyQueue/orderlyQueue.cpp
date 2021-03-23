// Source: https://leetcode.com/problems/orderly-queue/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(begin(S), end(S));
            return S;
        }
        string res = S;
        for (int i = 1; i < S.size(); i++) {
            res = min(res, S.substr(i) + S.substr(0, i));
        }
        return res;
    }
};
