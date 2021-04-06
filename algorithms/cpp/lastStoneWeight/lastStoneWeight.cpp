// Source: https://leetcode.com/problems/last-stone-weight/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s: stones) {
            q.push(s);
        }
        while (q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if (x == y) continue;
            q.push(abs(x - y));
        }
        return q.empty() ? 0 : q.top();
    }
};
