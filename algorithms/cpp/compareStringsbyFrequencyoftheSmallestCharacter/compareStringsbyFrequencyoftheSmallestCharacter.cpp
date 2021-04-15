// Source: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> qcnt, wcnt;
        for (auto& q: queries) {
            qcnt.push_back(freq(q));
        }
        for (auto& w: words) {
            wcnt.push_back(freq(w));
        }
        vector<int> res;
        for (int q: qcnt) {
            int cnt = 0;
            for (int w: wcnt) {
                if (w > q) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }

private:
    int freq(string& word) {
        vector<int> cnt(26, 0);
        for (char w: word) {
            cnt[w - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0)
                return cnt[i];
        }
        return 0;
    }
};
