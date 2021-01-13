// Source: https://leetcode.com/problems/text-justification/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cur;
        int cnt = 0;
        for (auto word: words) {
            if (cnt + cur.size() + word.size() > maxWidth) {
                for (int i = 0; i < maxWidth - cnt; i++) {
                    int base;
                    if (cur.size() == 1) base = 1;
                    else base = cur.size() - 1;
                    cur[i % base] += ' ';
                }
                string tmp;
                for(auto c: cur) {
                    tmp += c;
                }
                res.push_back(tmp);
                cur.clear();
                cnt = 0;
            }
            cur.push_back(word);
            cnt += word.size();
        }
        string tmp;
        for (int i = 0; i < cur.size(); i++) {
            if (i != cur.size() - 1) {
                cur[i] += ' ';
            }
            tmp += cur[i];
        }
        int n = maxWidth - tmp.size();
        for (int i = 0; i < n; i++) tmp += " ";
        res.push_back(tmp);
         
        return res;
    }
};
