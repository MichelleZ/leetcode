// Source: https://leetcode.com/problems/split-array-into-fibonacci-sequence/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        dfs(S, 0, 0, 0, res);
        return res;
    }

private:
    bool dfs(string S, int idx, int prev, long long sums, vector<int>& res) {
        if (idx == S.length()) return res.size() >= 3;
        long long cur = 0;
        for (int i = idx; i < S.length(); i++) {
            if (i > idx && S[idx] == '0') break;
            cur = cur * 10 + S[i] - '0';
            if (cur > INT_MAX) break;
            if (res.size() >= 2) {
                if (cur < sums) continue;
                else if (cur > sums) break;
            }
            res.push_back(cur);
            if (dfs(S, i + 1, cur, prev + cur, res)) return true;
            res.pop_back();
        }
        return false;
    }
};
