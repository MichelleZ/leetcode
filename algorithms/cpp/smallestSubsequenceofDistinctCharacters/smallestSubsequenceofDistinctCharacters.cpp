// Source: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        vector<int> cnt(128), visited(128);
        for (char c: s) cnt[c]++;
        for (char c: s) {
            cnt[c]--;
            if (visited[c]) continue;
            while (!res.empty() && c < res.back() && cnt[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += c;
            visited[c] = 1;
        }
        return res;
    }
};
