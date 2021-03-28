// Source: https://leetcode.com/problems/bag-of-tokens/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        std::sort(begin(tokens), end(tokens));
        int res = 0;
        int scores = 0;
        int i = 0;
        int j = tokens.size() - 1;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++scores);
            } else if (scores > 0) {
                P += tokens[j--];
                scores--;
            } else {
                break;
            }
        }
        return res;
    }
};
