// Source: https://leetcode.com/problems/k-similar-strings/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        queue<string> q;
        q.push(s1);
        int step = 0;
        unordered_set<string> visited;
        visited.insert(s1);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string s3 = q.front();
                q.pop();
                int i = 0;
                while (s3[i] == s2[i]) i++;
                for (int j = i + 1; j < s3.size(); j++) {
                    if (s3[j] != s2[i]) continue;
                    string s4 = s3;
                    swap(s4[i], s4[j]);
                    if (s4 == s2) return step + 1;
                    if (visited.count(s4)) continue;
                    visited.insert(s4);
                    q.push(s4);
                }
            }
            step++;
        }
        return -1;
    }
};
