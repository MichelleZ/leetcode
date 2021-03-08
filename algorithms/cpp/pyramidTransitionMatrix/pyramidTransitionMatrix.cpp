// Source: https://leetcode.com/problems/pyramid-transition-matrix/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> dic;
        for (string str: allowed) {
            dic[str.substr(0, 2)].insert(str[2]);
        }
        return dfs(bottom, "", dic);
    }

private:
    bool dfs(string cur, string above, unordered_map<string, unordered_set<char>>& dic) {
        if (cur.size() == 2 && above.size() == 1) return true;
        if (above.size() == cur.size() - 1) return dfs(above, "", dic);
        int pos = above.size();
        string base = cur.substr(pos, 2);
        if (dic.count(base)) {
            for (char c: dic[base]) {
                if (dfs(cur, above + string(1, c), dic)) {
                    return true;
                }
            }
        }
        return false;
    }
};
