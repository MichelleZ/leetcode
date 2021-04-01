// Source: https://leetcode.com/problems/find-common-characters/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> min_count(26, INT_MAX);
        for (const string& a: A) {
            vector<int> cnt(26, 0);
            for (auto& c: a) {
                cnt[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                min_count[i] = min(min_count[i], cnt[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            if (min_count[i] == INT_MAX) continue;
            for (int j = 0; j < min_count[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
