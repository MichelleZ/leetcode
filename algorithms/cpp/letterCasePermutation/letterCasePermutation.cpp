// Source: https://leetcode.com/problems/letter-case-permutation/
// Author: Miao Zhang
// Date:   2021-03-10

/***************************************************
 * A-Z: 65-98
 * a-z: 97-122
 * 1<<5 = 32
***************************************************/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, 0, res);
        return res;
    }

    void dfs(string S, int start, vector<string>& res) {
        if (start == S.length()) {
            res.push_back(S);
            return;
        }
        dfs(S, start + 1, res);
        if (!isalpha(S[start])) return;
        S[start] ^= (1 << 5);
        dfs(S, start + 1, res);
        S[start] ^= (1 << 5);
    }
};
