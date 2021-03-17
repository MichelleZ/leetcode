// Source: https://leetcode.com/problems/hand-of-straights/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cnts;
        for (auto& h: hand) cnts[h]++;
        while (!cnts.empty()) {
            auto it = cnts.begin();
            int start = it->first;
            for (int i = start; i < start + W; i++) {
                if (it == cnts.end() || it->first != i) return false;
                auto pre = it++;
                if (--(pre->second) == 0) cnts.erase(pre);
            }
        }
        return true;
    }
};
