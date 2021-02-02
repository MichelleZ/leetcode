// Source: https://leetcode.com/problems/remove-duplicate-letters/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int, int> counter;
        unordered_map<int, bool> visited;
        string res;
        for (char c: s) counter[c]++;
        for (char c: s) {
            --counter[c];
            if (visited[c]) continue;
            while (!res.empty() && counter[res.back()] && res.back() > c) {
                visited[res.back()] = false;
                res.pop_back();
            }
            visited[c] = true;
            res += c;
        }
        return res;
    }
};
