// Source: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto& k: knowledge) m[k[0]] = k[1];
        string res, cur;
        bool flag = false;
        for (char& c: s) {
            if (c == '(') {
                flag = true;
            } else if (c == ')') {
                flag = false;
                if (m.count(cur)) res += m[cur];
                else res += '?';
                cur = "";
            } else if (flag) {
                cur += c;
            } else {
                res += c;
            }
        }
        return res;
    }
};
