// Source: https://leetcode.com/problems/camelcase-matching/
// Author: Miao Zhang
// Date:   2021-04-03

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (const string& q: queries) {
            res.push_back(match(q, pattern));
        }
        return res;
    }

private:
    bool match(const string& q, const string& p) {
        cout << q << "," << p;
        int qn = q.length();
        int pn = p.length();
        int i = 0;
        int j = 0;
        for (i = 0; i < qn; i++) {
            if (j == pn && isupper(q[i])) return false;
            if ((j == pn || isupper(p[j])) && islower(q[i])) continue;
            if ((isupper(p[j]) || isupper(q[i])) && p[j] != q[i]) return false;
            if (islower(p[j]) && p[j] != q[i]) continue;
            j++;
        }
        return i == qn && j == pn;
    }
};
