// Source: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int maxUniqueSplit(string s) {
        int res = 1;
        int n = s.length();
        unordered_set<string> seen;
        function<void(int)> dfs = [&] (int start) {
            if (start == n) {
                res = max(res, (int)seen.size());
                return;
            }
            for (int i = start; i < n; i++) {
                string ss = s.substr(start, i - start + 1);
                if (!seen.insert(ss).second) continue;
                dfs(i + 1);
                seen.erase(ss);
            }
        };
        dfs(0);
        return res;
    }
};
