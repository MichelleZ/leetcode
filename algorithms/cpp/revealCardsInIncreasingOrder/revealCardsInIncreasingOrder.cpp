// Source: https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        deque<int> q;
        for (int i = 0; i < n; i++) {
            q.push_back(i);
        }
        vector<int> res(n);
        std::sort(deck.begin(), deck.end());
        for (auto& d: deck) {
            int idx = q.front();
            q.pop_front();
            res[idx] = d;
            if (!q.empty()) {
                int mvidx = q.front();
                q.pop_front();
                q.push_back(mvidx);
            }
        }
        return res;
    }
};
