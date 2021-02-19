// Source: https://leetcode.com/problems/ipo/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> heap;
        multiset<pair<int, int>> capital; // {capital, profits}
        for (int i = 0; i < Profits.size(); i++) {
            if (Profits[i] <= 0) continue;
            if (Capital[i] <= W) {
                heap.push(Profits[i]);
            } else {
                capital.emplace(Capital[i], Profits[i]);
            }
        }
        auto it = capital.cbegin();
        while (!heap.empty() && k--) {
            W += heap.top();
            heap.pop();
            while (it != capital.end() && it->first <= W) {
                heap.push(it++->second);
            }
        }
        return W;
    }
};
