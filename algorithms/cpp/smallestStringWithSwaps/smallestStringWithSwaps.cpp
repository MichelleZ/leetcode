// Source: https://leetcode.com/problems/smallest-string-with-swaps/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> g(n);
        for (const auto& p: pairs) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        unordered_set<int> seen;
        vector<int> idx;
        string t;
        
        function<void(int)> dfs = [&] (int i) {
            if (seen.count(i)) return;
            seen.insert(i);
            idx.push_back(i);
            t += s[i];
            for (int nxt: g[i]) dfs(nxt);
        };
        
        for (int i = 0; i < n; i++) {
            if (seen.count(i)) continue;
            idx.clear();
            t.clear();
            dfs(i);
            sort(begin(idx), end(idx));
            sort(begin(t), end(t));
            for (int k = 0; k < idx.size(); k++) {
                s[idx[k]] = t[k];
            }
        }
        return s;
    }
};
