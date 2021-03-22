// Source: https://leetcode.com/problems/find-and-replace-pattern/
// Author: Miao Zhang
// Date:   2021-03-22

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& w: words) {
            if (match(w, pattern)) res.push_back(w);
        }
        return res;   
    }

private:
    bool match(const string& w, const string& p) {
        vector<int> last_pos_w(128, INT_MIN);
        vector<int> last_pos_p(128, INT_MIN);
        for (int i = 0; i < w.size(); i++) {
            if (last_pos_w[w[i]] != last_pos_p[p[i]]) {
                return false;
            } else {
                last_pos_w[w[i]] = last_pos_p[p[i]] = i;
            }
        }
        return true;
    }
};
