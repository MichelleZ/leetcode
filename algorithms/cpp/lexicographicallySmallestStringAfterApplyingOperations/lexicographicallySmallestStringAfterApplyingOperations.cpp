// Source: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        string res(s);
        function<void(string)> dfs = [&] (const string& s) {
            if (!seen.insert(s).second) return;
            res = min(res, s);
            string t(s);
            for (int i = 1; i < t.size(); i += 2) {
                t[i] = (t[i] - '0' + a) % 10 + '0';
            }
            dfs(t);
            dfs(s.substr(b) + s.substr(0, b));
        };
        dfs(s);
        return res;
    }
};
