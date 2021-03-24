// Source: https://leetcode.com/problems/word-subsets/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> comb(26);
        for (const string& b: B) {
            vector<int> cur(count(b));
            for (int i = 0; i < 26; i++) {
                comb[i] = max(comb[i], cur[i]);
            }
        }
        
        vector<string> res;
        for (const string& a: A) {
            vector<int> cur(count(a));
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (cur[i] < comb[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(a);
        }
        return res;
    }

private:
    vector<int> count(const string& a) {
        vector<int> cnt(26);
        for (char c: a) {
            cnt[c - 'a']++;
        }
        return cnt;
    }
};
