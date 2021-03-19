// Source: https://leetcode.com/problems/advantage-shuffle/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A), end(A));
        vector<int> res;
        for (int b: B) {
            auto it = s.upper_bound(b);
            if (it == s.end()) it = s.begin();
            res.push_back(*it);
            s.erase(it);
        }
        return res;
    }
};
