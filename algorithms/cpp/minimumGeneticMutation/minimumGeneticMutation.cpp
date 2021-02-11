// Source: https://leetcode.com/problems/minimum-genetic-mutation/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);

        int mutation = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = std::move(q.front());
                q.pop();
                if (cur == end) return mutation;
                for (string & gene: bank) {
                    if (visited.count(gene) || !validMutation(cur, gene)) continue;
                    visited.insert(gene);
                    q.push(gene);
                }
            }
            mutation++;
        }
        return -1;
    }

private:
    bool validMutation(string& s1, string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i] && cnt++) return false;
        }
        return true;
    }
};
