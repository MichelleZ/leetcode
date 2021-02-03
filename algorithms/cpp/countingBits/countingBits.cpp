// Source: https://leetcode.com/problems/counting-bits/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        while (res.size() <= num) {
            vector<int> tmp;
            for (auto &n: res) {
                tmp.push_back(n + 1);
            }
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return vector<int>(res.begin(), res.begin() + num + 1);
    }
};
