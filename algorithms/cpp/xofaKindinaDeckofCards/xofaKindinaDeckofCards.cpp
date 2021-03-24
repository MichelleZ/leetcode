// Source: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnts;
        for (int card: deck) cnts[card]++;
        for (int i = 2; i <= deck.size(); i++) {
            if (deck.size() % i) continue;
            bool ok = true;
            for (const auto& p: cnts) {
                if (p.second % i) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};
