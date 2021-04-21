// Source: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n - minSize + 1; i++) {
            string cur = s.substr(i, minSize);
            unordered_set<char> ss(cur.begin(), cur.end());
            if (ss.size() <= maxLetters) {
                m[cur]++;
                res = max(res, m[cur]);
            }
        }
        return res;
    }
};
