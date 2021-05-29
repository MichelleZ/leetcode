// Source: https://leetcode.com/problems/maximum-number-of-eaten-apples/
// Author: Miao Zhang
// Date:   2021-05-29

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int res = 0;
        for (int i = 0; i < n || !q.empty(); i++) {
            if (i < n && apples[i])
                q.emplace(i + days[i], i);
            while (!q.empty() &&
                   (q.top().first <= i || apples[q.top().second] == 0)) {
                q.pop();
            }
            if (q.empty()) continue;
            apples[q.top().second]--;
            res++;
        }
        return res;
    }
};
