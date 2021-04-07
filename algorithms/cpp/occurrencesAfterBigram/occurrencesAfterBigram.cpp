// Source: https://leetcode.com/problems/occurrences-after-bigram/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        istringstream is(text);
        string t, prepre, pre;
        while (is >> t) {
            if (prepre == first && pre == second) {
                res.push_back(t);
            }
            prepre = pre;
            pre = t;
        }
        return res;
    }
};
