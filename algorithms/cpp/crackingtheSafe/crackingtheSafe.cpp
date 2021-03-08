// Source: https://leetcode.com/problems/cracking-the-safe/
// Author: Miao Zhang
// Date:   2021-03-07

class Solution {
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        visited = unordered_set<string>();
        string start;
        for (int i = 0; i < n - 1; i++) {
            start.push_back('0');
        }
        dfs(start, k);
        res += start;
        return res;
    }

private:
    unordered_set<string> visited;
    string res;

    void dfs(string node, int k) {
        for (int edge = 0; edge < k; edge++) {
            string val = node + to_string(edge);
            if (!visited.count(val)) {
                visited.insert(val);
                dfs(val.substr(1), k);
                res += to_string(edge);
            }
        }
    }
};
