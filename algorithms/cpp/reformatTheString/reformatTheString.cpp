// Source: https://leetcode.com/problems/reformat-the-string/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    string reformat(string s) {
        string q1;
        string q2;
        for (char c: s) {
            if (isalpha(c)) q1 += c;
            else q2 += c;
        }
        if (q1.length() < q2.length()) {
            swap(q1, q2);
        }
        if (q1.length() > q2.length() + 1) {
            return "";
        }
        string res;
        while (!q1.empty()) {
            res += q1.back();
            q1.pop_back();
            if (q2.empty()) break;
            res += q2.back();
            q2.pop_back();
        }
        return res;
    }
};
